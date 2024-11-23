
// send 'databyte' to 'port'
int outp(unsigned port, int databyte);

// read a byte from 'port'
int inp(unsigned port);

/*
The constant PORTADDRESS in the code is defined as the 
location of the communication port. The code assumes bit 0 of this 
location controls the 1-Wire bus. Setting this bit to 0 drives the 
1-Wire line low. Setting this bit to 1 releases the 1-Wire to be 
pulled up by the resistor pullup or pulled down by a 1-Wire slave device.

The function tickDelay in the code is a user-generated routine to wait 
a variable number of 1/4 microseconds. This function varies for each 
unique hardware platform running so it is not implemented here. Below 
is the function declaration for the tickDelay along with a function 
SetSpeed to set the recommended standard and overdrive speed tick values.
*/

// Pause for exactly 'tick' number of ticks = 0.25us
void tickDelay(int tick); // Implementation is platform specific

// 'tick' values
int A,B,C,D,E,F,G,H,I,J;

//-----------------------------------------------------------------------------
// Set the 1-Wire timing to 'standard' (standard=1) or 'overdrive' (standard=0).
//
void SetSpeed(int standard)
{
        // Adjust tick values depending on speed
        if (standard)
        {
                // Standard Speed
                A = 6 * 4;
                B = 64 * 4;
                C = 60 * 4;
                D = 10 * 4;
                E = 9 * 4;
                F = 55 * 4;
                G = 0;
                H = 480 * 4;
                I = 70 * 4;
                J = 410 * 4;
        }
        else
        {
                // Overdrive Speed
                A = 1.5 * 4;
                B = 7.5 * 4;
                C = 7.5 * 4;
                D = 2.5 * 4;
                E = 0.75 * 4;
                F = 7 * 4;
                G = 2.5 * 4;
                H = 70 * 4;
                I = 8.5 * 4;
                J = 40 * 4;
        }
}

//-----------------------------------------------------------------------------
// Generate a 1-Wire reset, return 1 if no presence detect was found,
// return 0 otherwise.
// (NOTE: Does not handle alarm presence from DS2404/DS1994)
//
int OWTouchReset(void)
{
        int result;

        tickDelay(G);
        outp(PORTADDRESS,0x00); // Drives DQ low
        tickDelay(H);
        outp(PORTADDRESS,0x01); // Releases the bus
        tickDelay(I);
        result = inp(PORTADDRESS) ^ 0x01; // Sample for presence pulse from slave
        tickDelay(J); // Complete the reset sequence recovery
        return result; // Return sample presence pulse result
}

//-----------------------------------------------------------------------------
// Send a 1-Wire write bit. Provide 10us recovery time.
//
void OWWriteBit(int bit)
{
        if (bit)
        {
                // Write '1' bit
                outp(PORTADDRESS,0x00); // Drives DQ low
                tickDelay(A);
                outp(PORTADDRESS,0x01); // Releases the bus
                tickDelay(B); // Complete the time slot and 10us recovery
        }
        else
        {
                // Write '0' bit
                outp(PORTADDRESS,0x00); // Drives DQ low
                tickDelay(C);
                outp(PORTADDRESS,0x01); // Releases the bus
                tickDelay(D);
        }
}

//-----------------------------------------------------------------------------
// Read a bit from the 1-Wire bus and return it. Provide 10us recovery time.
//
int OWReadBit(void)
{
        int result;

        outp(PORTADDRESS,0x00); // Drives DQ low
        tickDelay(A);
        outp(PORTADDRESS,0x01); // Releases the bus
        tickDelay(E);
        result = inp(PORTADDRESS) & 0x01; // Sample the bit value from the slave
        tickDelay(F); // Complete the time slot and 10us recovery

        return result;
}

//-----------------------------------------------------------------------------
// Write 1-Wire data byte
//
void OWWriteByte(int data)
{
        int loop;

        // Loop to write each bit in the byte, LS-bit first
        for (loop = 0; loop < 8; loop++)
        {
                OWWriteBit(data & 0x01);

                // shift the data byte for the next bit
                data >>= 1;
        }
}

//-----------------------------------------------------------------------------
// Read 1-Wire data byte and return it
//
int OWReadByte(void)
{
        int loop, result=0;

        for (loop = 0; loop < 8; loop++)
        {
                // shift the result to get it ready for the next bit
                result >>= 1;

                // if result is one, then set MS bit
                if (OWReadBit())
                        result |= 0x80;
        }
        return result;
}

//-----------------------------------------------------------------------------
// Write a 1-Wire data byte and return the sampled result.
//
int OWTouchByte(int data)
{
        int loop, result=0;

        for (loop = 0; loop < 8; loop++)
        {
                // shift the result to get it ready for the next bit
                result >>= 1;

                // If sending a '1' then read a bit else write a '0'
                if (data & 0x01)
                {
                        if (OWReadBit())
                                result |= 0x80;
                }
                else
                        OWWriteBit(0);

                // shift the data byte for the next bit
                data >>= 1;
        }
        return result;
}

//-----------------------------------------------------------------------------
// Write a block 1-Wire data bytes and return the sampled result in the same
// buffer.
//
void OWBlock(unsigned char *data, int data_len)
{
        int loop;

        for (loop = 0; loop < data_len; loop++)
        {
                data[loop] = OWTouchByte(data[loop]);
        }
}

//-----------------------------------------------------------------------------
// Set all devices on 1-Wire to overdrive speed. Return '1' if at least one
// overdrive capable device is detected.
//
int OWOverdriveSkip(unsigned char *data, int data_len)
{
        // set the speed to 'standard'
        SetSpeed(1);

        // reset all devices
        if (OWTouchReset()) // Reset the 1-Wire bus
                return 0; // Return if no devices found

        // overdrive skip command
        OWWriteByte(0x3C);

        // set the speed to 'overdrive'
        SetSpeed(0);

        // do a 1-Wire reset in 'overdrive' and return presence result
        return OWTouchReset();
}

//-----------------------------------------------------------------------------
// Read and return the page data and SHA-1 message authentication code (MAC)
// from a DS2432.
//
int ReadPageMAC(int page, unsigned char *page_data, unsigned char *mac)
{
        int i;
        unsigned short data_crc16, mac_crc16;

        // set the speed to 'standard'
        SetSpeed(1);

        // select the device
        if (OWTouchReset()) // Reset the 1-Wire bus
                return 0; // Return if no devices found

        OWWriteByte(0xCC); // Send Skip ROM command to select single device

        // read the page
        OWWriteByte(0xA5); // Read Authentication command
        OWWriteByte((page << 5) & 0xFF); // TA1
        OWWriteByte(0); // TA2 (always zero for DS2432)

        // read the page data
        for (i = 0; i < 32; i++)
                page_data[i] = OWReadByte();
        OWWriteByte(0xFF);

        // read the CRC16 of command, address, and data
        data_crc16 = OWReadByte();
        data_crc16 |= (OWReadByte() << 8);

        // delay 2ms for the device MAC computation
        // read the MAC
        for (i = 0; i < 20; i++)
                mac[i] = OWReadByte();

        // read CRC16 of the MAC
        mac_crc16 = OWReadByte();
        mac_crc16 |= (OWReadByte() << 8);

        // check CRC16...
        return 1;
}

