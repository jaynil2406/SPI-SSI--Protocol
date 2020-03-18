/*
 * ledpb.h
 *
 *  Created on: Mar 6, 2020
 *      Author: JaYniL~LM10
 */

#ifndef LEDPB_H_
#define LEDPB_H_


#define RED_LED      (*((volatile uint32_t *)(0x42000000 + (0x400253FC-0x40000000)*32 + 1*4)))
#define GREEN_LED    (*((volatile uint32_t *)(0x42000000 + (0x400253FC-0x40000000)*32 + 3*4)))
#define PUSH_BUTTON  (*((volatile uint32_t *)(0x42000000 + (0x400253FC-0x40000000)*32 + 4*4)))

#define GREEN_LED_MASK 8
#define RED_LED_MASK 2
#define PUSH_BUTTON_MASK 16


void initHw();
void inttimer1A();
void sysTIMERINIT();

#endif /* LEDPB_H_ */
