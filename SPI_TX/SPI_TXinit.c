/*
 * SPI_init.c
 *
 *  Created on: Mar 17, 2020
 *      Author: JaYniL~LM10
 */

#include <stdint.h>
#include<stdlib.h>
#include<stdio.h>
#include <SPI_TXinit.h>
#include "tm4c123gh6pm.h"

void SSIinit(void)
{
    SYSCTL_RCC_R = SYSCTL_RCC_XTAL_16MHZ | SYSCTL_RCC_OSCSRC_MAIN | SYSCTL_RCC_USESYSDIV | (4 << SYSCTL_RCC_SYSDIV_S);
    SYSCTL_GPIOHBCTL_R = 0;
    SYSCTL_RCGCSSI_R = SYSCTL_RCGCSSI_R2;            // turn-on SSI2 clocking
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOB;

    GPIO_PORTB_DIR_R |= CLK_MASK|TX_MASK|CS_NOT_MASK;                        // make bits 4 and 7 outputs
    GPIO_PORTB_AFSEL_R |= CLK_MASK|TX_MASK|CS_NOT_MASK;                      // select alternative functions for MOSI, SCLK pins
    GPIO_PORTB_PCTL_R = GPIO_PCTL_PB7_SSI2TX | GPIO_PCTL_PB4_SSI2CLK |GPIO_PCTL_PB5_SSI2FSS; // map alt fns to SSI2
    GPIO_PORTB_DEN_R |= CLK_MASK|TX_MASK |CS_NOT_MASK;                        // enable digital operation on TX, CLK pins
    GPIO_PORTB_PUR_R |= CLK_MASK|CS_NOT_MASK;                        // must be enabled when SPO=1

       // Configure the SSI2 as a SPI master, mode 3, 16bit operation, 4 MHz bit rate
    SSI2_CR1_R &= ~SSI_CR1_SSE  ;                      // turn off SSI2 to allow re-configuration
    SSI2_CR1_R = 0  ;                                  // select master mode
    SSI2_CC_R = 0 ;                                   // select system clock as the clock source
    SSI2_CPSR_R = 10;                                // set bit rate to 4 MHz (if SR=0 in CR0)
    SSI2_CR0_R =   SSI_CR0_FRF_MOTO | SSI_CR0_DSS_16; // set SR=0, mode 3 (SPH=0, SPO=0), 16-bit
    SSI2_CR1_R |= SSI_CR1_SSE;                       // turn on SSI2
}

