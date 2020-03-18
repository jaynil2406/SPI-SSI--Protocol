/*
 * getString.c
 *
 *  Created on: Mar 6, 2020
 *      Author: JaYniL~LM10
 */
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
#include "uart0.h"
#include "getString.h"



char tolow(char c)
{
    if (c == 'A')
        c = 'a';
      else if (c == 'B')
        c = 'b';
      else if (c == 'C')
        c = 'c';
      else if (c == 'D')
        c = 'd';
      else if (c == 'E')
        c = 'e';
      else if (c == 'F')
        c = 'f';
      else if (c == 'G')
        c = 'g';
      else if (c == 'H')
        c = 'h';
      else if (c == 'I')
        c = 'i';
      else if (c == 'J')
        c = 'j';
      else if (c == 'K')
        c = 'k';
      else if (c == 'L')
        c = 'l';
      else if (c == 'M')
        c = 'm';
      else if (c == 'N')
        c = 'n';
      else if (c == 'O')
        c = 'o';
      else if (c == 'P')
        c = 'p';
      else if (c == 'Q')
        c = 'q';
      else if (c == 'R')
        c = 'r';
      else if (c == 'S')
        c = 's';
      else if (c == 'T')
        c = 't';
      else if (c == 'U')
        c = 'u';
      else if (c == 'V')
        c = 'v';
      else if (c == 'W')
        c = 'w';
      else if (c == 'X')
        c = 'x';
      else if (c == 'Y')
        c = 'y';
      else if (c == 'Z')
        c = 'z';

      else
        return c;
 return c;
}
unsigned char getcUart0String(char str[], uint8_t x)
{

//    count ++;
    while(1)
    {

   char c = getcUart0();

//putcUart0(c);
   if ((c == 8) || (c == 127))
   {
       if(step2.count >0)
       {
           step2.count--;
           str[step2.count]= tolow(c);
       }
       else
       {
           c =0;
           c = getcUart0();
       }
   }

   if ((c == 13) || (c == 10))
            {
               if(step2.count !=0 )
                   {
                       str[step2.count]=0;
                       putsUart0("\r\n");
                       putsUart0("UART0 String:");
                       putsUart0(str);
                       putsUart0("\r\n");

                       step2.count =0;
                       c =0;
                       break;
                   }
            }
     if(c >= 32)
       {

               str[step2.count++] = tolow(c);

       }
       else if(step2.count ==x)
                 {
                     str[step2.count] =0;
                     break ;
                 }
}
return 0;
}
void parseString()
{

    for(step3.e=0,step3.f=0;step2.str[step3.e]!='\0';step3.e++)
    {
        //Checking if the String is A to Z or a to z
        //Checking if string is 0 to 9 or " . " or " , "
        step3.y=1;
        step3.x=1;
        if(((0x41 <= (step2.str[step3.e]))&& ((step2.str[step3.e])<=0x5A)) || ((0x61 <= (step2.str[step3.e])) && ((step2.str[step3.e]) <= 0x7A))||
                ((0x30 <= (step2.str[step3.e] )) && ((step2.str[step3.e])  <= 0x39))|| (0x2E== (step2.str[step3.e])) || (0x2C == (step2.str[step3.e])) || (0x2D== (step2.str[step3.e])))
        {
            step3.x =0;
        }

        else
        {

            step3.y =0;

        }

        if( step3.e != 0  && step3.x ==0 )
        {
            step3.e--;
            if(((0x41 <= (step2.str[step3.e]))&& ((step2.str[step3.e])<=0x5A)) || ((0x61 <= (step2.str[step3.e])) && ((step2.str[step3.e]) <= 0x7A))||
                    ((0x30 <= (step2.str[step3.e] )) && ((step2.str[step3.e])  <= 0x39))|| (0x2E== (step2.str[step3.e])) || (0x2C == (step2.str[step3.e])) || (0x2D== (step2.str[step3.e])))
            {
                step3.e++;
            }
            else
            {
                step3.e++;
                step3.pos[step3.f] = step3.e;
                step3.f++;
                step3.argCount ++;
            }
        }
        else if(step3.e ==0 && step3.x == 0  )
            {
            step3.pos[step3.f] = step3.e;
            step3.f++;
            step3.argCount++;
            }
        else if(step3.y ==0)
        {
            step2.str[step3.e] = '\0';

        }
    }

    //********************************************************************************************
    //***************************STEP4: GETARGINT GETARGFLOAT STRINGCOMPARE AND ISCOMMAND**********
    //********************************************************************************************
    //********************************************************************************************

}
char *getArgString(uint8_t argNo)
{
    if(argNo <= step3.argCount)
    {
        return &step2.str[step3.pos[argNo+1]];
    }
    else
    {
        putsUart0("TRASH FOUND");
    }


return &step2.str[step3.pos[argNo]] ;
}

uint32_t getArgInt(char* argString)
{
    uint32_t value;
    value = atoi(argString);
    return value;
}
float getArgFloat(char* argString)
{
    float value1;
    value1 = atof(argString);
    return value1;
}

int stringcompare(char *str1, char *str2)
{

    while(*str1 && *str1 == *str2)
      {
          str2++;
          str1++;
      }
    if(*str1 - *str2 == 32)
    {
        str1++;
        str2++;
        if(*str1 - *str2 == 32)
            return 0;
    }
  return *str1 - *str2;
}

bool is_command(char* strcmd, uint8_t minArg)

{
step3.q = stringcompare(&step2.str[step3.pos[0]],strcmd);
  if(step3.argCount > minArg  && step3.q==0 )
            {
                return true ;//*strcmd - &str[pos[0]] ;;
            }
            else
            {
                return false;
            }
}
