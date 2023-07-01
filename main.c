/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

// defining varaibles globally
uint8_t g_ReadDIpinSts = 0b00100000;
uint8_t g_AppDIpinSts = 0b00000000;

int count = 0;

int ISR_DIsampling()
{
    // Updating g_AppDIpinSts only after 10 ISR calls
    if (count >= 10) {
        g_AppDIpinSts = g_ReadDIpinSts;
        count = 0; // Resetting the counter
    }

    count++; // Incrementing the counter
    return 0; // Returning zero
}

//Main program
int main()
{
    while (1) {
        
        ISR_DIsampling();// Calling the ISR_DIsampling function
        printf("g_AppDIpinSts: 0x%02X\n", g_AppDIpinSts);
        usleep(10000);//delay of 10 milliseconds
        
        
    }
    return 0;//returning zero to the main program
}
