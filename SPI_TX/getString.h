/*
 * getString.h
 *
 *  Created on: Mar 6, 2020
 *      Author: JaYniL~LM10
 */

#ifndef GETSTRING_H_
#define GETSTRING_H_

#define MAX_CHAR 80
#define MAX_FIELDS 10

typedef struct _step2_variables
{
    uint8_t count;
    char str[MAX_CHAR+1];

}step2_var;
typedef struct _step_variables
{
    uint8_t e,f,q,x,y,pos[MAX_FIELDS],argCount ;
}step3_var;
step2_var step2;
step3_var step3;
char tolow(char c);
unsigned char getcUart0String(char str[], uint8_t x);
void parseString();
char *getArgString(uint8_t argNo);
uint32_t getArgInt(char* argString);
float getArgFloat(char* argString);
int stringcompare(char *str1, char *str2);
bool is_command(char* strcmd, uint8_t minArg);

#endif /* GETSTRING_H_ */
