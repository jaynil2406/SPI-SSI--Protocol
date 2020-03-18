#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "SPI_RXinit.h"
#include "tm4c123gh6pm.h"
#include "ledpb.h"

int main(void)
{
    int RX=0;
   initHw();
   SSIinit();
   while(1)
   {    SSI2_DR_R =0;
       RX = SSI2_DR_R;
       if(RX==11){RED_LED=0;}

       if(RX==1)
       {    GREEN_LED=0;    RED_LED=1;  }

       if(RX==33)
           GREEN_LED=0;
       if(RX==3) {  RED_LED=0; GREEN_LED=1;  }
   }


}
