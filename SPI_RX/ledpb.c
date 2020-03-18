/*
 * ledpb.c
 *
 *  Created on: Mar 6, 2020
 *      Author: JaYniL~LM10
 */



#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
#include "ledpb.h"

// Initialize Hardware
// REQUIRED: Add initialization for blue, orange, red, green, and yellow LEDs
//           6 pushbuttons, and uart
void initHw()
{

        // Configure HW to work with 16 MHz XTAL, PLL enabled, sysdivider of 5, creating system clock of 40 MHz
        SYSCTL_RCC_R = SYSCTL_RCC_XTAL_16MHZ | SYSCTL_RCC_OSCSRC_MAIN | SYSCTL_RCC_USESYSDIV | (4 << SYSCTL_RCC_SYSDIV_S);

        // Set GPIO ports to use APB (not needed since default configuration -- for clarity)
        SYSCTL_GPIOHBCTL_R = 0;

        // Enable GPIO port F peripherals
        SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF;

        // Configure LED and pushbutton pins
        GPIO_PORTF_DIR_R = GREEN_LED_MASK | RED_LED_MASK;  // bits 1 and 3 are outputs, other pins are inputs
        GPIO_PORTF_DR2R_R = GREEN_LED_MASK | RED_LED_MASK; // set drive strength to 2mA (not needed since default configuration -- for clarity)
        GPIO_PORTF_DEN_R = PUSH_BUTTON_MASK | GREEN_LED_MASK | RED_LED_MASK;  // enable LEDs and pushbuttons
        GPIO_PORTF_PUR_R = PUSH_BUTTON_MASK; // enable internal pull-up for push button







}
void inttimer1A()
{
    SYSCTL_RCGCTIMER_R |= SYSCTL_RCGCTIMER_R1;
    TIMER1_CTL_R &= ~TIMER_CTL_TAEN;
    TIMER1_CFG_R = TIMER_CFG_32_BIT_TIMER;
    TIMER1_TAMR_R = TIMER_TAMR_TAMR_PERIOD |  TIMER_TAMR_TACDIR;
    TIMER1_TAILR_R = 0xFFFFFFFF;


}
void sysTIMERINIT()
{
    NVIC_ST_CTRL_R     = 0;
        NVIC_ST_CURRENT_R  = 0;
        NVIC_ST_RELOAD_R   = 0x9C3F;
        NVIC_ST_CTRL_R     = 7;
}
