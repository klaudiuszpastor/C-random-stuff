/*Determine if a year is a leap year*/

// if year is not divisible by 4 
// it is common year
// if year is not divisible by 100
// it is a leap year
// if year is not divisible by 400
// it is common year
// else
// it is leap year

#include <stdio.h>
#include <stdbool.h>

bool leap_year (int year);

int main (void){
    for (int i = 1500; i<1600; i++){
        if (leap_year(i))
            printf("%d is leap year\n",i);
        else
            printf("%d is a common year\n",i);
    }
}

bool leap_year(int year){
    if (year % 4 != 0)
        return false;
    else if (year % 100 != 0)
        return true;
    else if (year % 100 !=0)
        return false;
    else
        return true;
}