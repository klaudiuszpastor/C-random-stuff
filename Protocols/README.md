## 1-Wire

The four basic operations of a 1-Wire bus are Reset, Write 1 bit, Write 0 bit,
and Read bit. Byte functions can then be derived from multiple calls to the bit
operations. The time values provided produce the most robust 1-Wire master for
communication with all 1-Wire devices over various line conditions.

1. The communication port must be bidirectional, its output is open-drain, and
there is a weak pullup on the line. This is requrement of any 1-Wire bus.
2. The system must be capable of generating an accurate and repeatable 1µs 
delay for standard speed and 0.25µs delay for overdrive speed.
3. The communication operations must not be interrupted while being generated.

The time it takes to perform one bit of communication is called a time slot in
the device data sheets. Byte functions can then be derived from multiple calls
to the bit operations. 

**Reset Sequence in 1-Wire**

Communication starts with the master device generating a special sequence called 
a reset. This sequence informs the slave devices about the start of the transmission.

The **reset sequence**, indicating the beginning of a 1-Wire transmission, starts 
with a low signal held for at least 480 μs. Then, the master releases the line and 
waits for confirmation from the slave device. After approximately 70 μs, the line 
state is checked – if a slave device is present, the master detects a low state on 
the line. Before continuing communication, the master must wait an additional period, 
typically 410 μs.


**Data Reading in 1-Wire**

Data reading is also initiated by the master device. In this case, the master forces 
the line low for 6 μs, then waits for 9 μs, and then reads the state of the line. A 
low state indicates the reception of a bit representing `0`, while a high state indicates 
`1`. After reading the bit, the master must wait 55 μs before initiating the next 
transmission.


**Data Transmission (Bit Encoding) in 1-Wire**

Similar to decoding NEC signals on STM32L4, we also need to understand how 
individual bits are encoded in 1-Wire communication, as a logical one is not simply 
represented by a continuous high state, and so on. 

In 1-Wire, sending a bit representing a logical `1` involves 6 μs of a low state 
followed by 64 μs of a high state. On the other hand, a logical `0` is represented 
by holding the line low for 60 μs, followed by a high state for the next 10 μs.
