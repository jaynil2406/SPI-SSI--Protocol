#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "SPI_TXinit.h"
#include "tm4c123gh6pm.h"
#include "ledpb.h"
#include "getString.h"
#include "stringReplacement.h"
#include "uart0.h"

int main(void)
{
    int a=0;
   initHw();
   initUart0();
   SSIinit();
   SSI2_DR_R =0;
   while(1)
   {
   getcUart0String(step2.str, MAX_CHAR);
   parseString();
   if(is_command("red",1))
   {
       uint8_t q=10,w=10;
       q=stringcompare(getArgString(0),"on");
       if(q==0)
       {     a =1; putsUart0("RED_ON");}
       w=stringcompare(getArgString(0),"off");
       if(w==0)
       {     a = 11; putsUart0("RED_OFF"); }
   }
   else if(is_command("green",1))
   {
       uint8_t q=10,w=10;
       q=stringcompare(getArgString(0),"on");
       if(q==0) { a =3; putsUart0("GREEN_ON"); }
       w=stringcompare(getArgString(0),"off");
       if(w==0){ a = 33; putsUart0("GREEN_OFF"); }
   }
   else
       putsUart0("Enter a Valid Command:\r\n :) :) \r\n");


       SSI2_DR_R =a;
   }

}
