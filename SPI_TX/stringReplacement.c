/*
 * stringReplacement.c
 *
 *  Created on: Mar 6, 2020
 *      Author: JaYniL~LM10
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
#include "uart0.h"



void string_copy( const char source_string[] ,  char destination_string[])
{
    int b=0;
    for(;source_string[b] != '\0';b++)
      destination_string[b] = source_string[b];
    destination_string[b] = '\0';
}
void roder(char* string, int length )
{
    int i = 0;
    int  j = length - 1;
    int lc;
    for(;i<j;i++)
    {
        lc = string[i];
        string[i] = string[j];
        string[j] = lc;
        j--;
    }
}
int itoc(int z, char string[])
{
    int i = 0;
    while (z)
    {
        string[i++] = (z % 10) + '0';
        z /= 10;
    }


    roder(string, i);
    string[i] = '\0';
    return i;
}
void name_display()
{
    putsUart0("***************************************\r\n");
    putsUart0("Project: RTOS \r\n");
    putsUart0("Name: JAYNIL PATEL\r\n");
    putsUart0("ID: 1001678013\r\n");
    putsUart0("Email: jaynilvasantbha.patel@mavs.edu\r\n");
    putsUart0("***************************************\r\n");
}

uint8_t nstrlength(char a[])
{
        uint8_t i;
        for(i=0; a[i]!='\0'; ++i);
        return i;
}
