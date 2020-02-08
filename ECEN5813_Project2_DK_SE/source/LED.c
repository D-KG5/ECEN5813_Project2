/*
 * LED.c
 *
 *  Created on: Feb 8, 2020
 *      Author: Dhruva
 */
#include <stdio.h>
#include "board.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"

#include "def.h"

// initialize RGB LEDs
void LED_init(void){
    // https://github.com/alexander-g-dean/ESF/blob/master/Code/Chapter_2/Source/main.c
    // set GPIO for RGB LED Pins
	// Make 3 pins GPIO
	PORTB->PCR[RED_LED_SHIFT] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[RED_LED_SHIFT] |= PORT_PCR_MUX(1);
	PORTB->PCR[GREEN_LED_SHIFT] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[GREEN_LED_SHIFT] |= PORT_PCR_MUX(1);
	PORTD->PCR[BLUE_LED_SHIFT] &= ~PORT_PCR_MUX_MASK;
	PORTD->PCR[BLUE_LED_SHIFT] |= PORT_PCR_MUX(1);

	// Set ports to outputs
	PTB->PDDR |= MASK(RED_LED_SHIFT) | MASK(GREEN_LED_SHIFT);
	PTD->PDDR |= MASK(BLUE_LED_SHIFT);

	PTB->PCOR |= MASK(RED_LED_SHIFT) | MASK(GREEN_LED_SHIFT);
	PTD->PCOR |= MASK(BLUE_LED_SHIFT);
}

// turn on LED by colour
void LED_on(uint8_t color){
	// set RGB LED Pins
	switch(color){
	case RED:
		PTB->PCOR = MASK(RED_LED_SHIFT);
		PTB->PSOR = MASK(GREEN_LED_SHIFT);
		PTD->PSOR = MASK(BLUE_LED_SHIFT);
#if DEBUG
		PRINTF("RED ON\r\n");
#endif
		break;
	case GREEN:
		PTB->PSOR = MASK(RED_LED_SHIFT);
		PTB->PCOR = MASK(GREEN_LED_SHIFT);
		PTD->PSOR = MASK(BLUE_LED_SHIFT);
#if DEBUG
		PRINTF("GREEN ON\r\n");
#endif
		break;
	case BLUE:
		PTB->PSOR = MASK(RED_LED_SHIFT);
		PTB->PSOR = MASK(GREEN_LED_SHIFT);
		PTD->PCOR = MASK(BLUE_LED_SHIFT);
#if DEBUG
		PRINTF("BLUE ON\r\n");
#endif
		break;
	case ALL:
		PTB->PCOR = MASK(RED_LED_SHIFT);
		PTB->PCOR = MASK(GREEN_LED_SHIFT);
		PTD->PCOR = MASK(BLUE_LED_SHIFT);
#if DEBUG
		PRINTF("ALL ON\r\n");
#endif
		break;
	default:
		PRINTF("ERROR\r\n");
	}
}

// turn off LED by colour
void LED_off(uint8_t color){
	// clear RGB LED Pins
	switch(color){
	case RED:
		PTB->PSOR = MASK(RED_LED_SHIFT);
#if DEBUG
		PRINTF("RED OFF\r\n");
#endif
		break;
	case GREEN:
		PTB->PSOR = MASK(GREEN_LED_SHIFT);
#if DEBUG
		PRINTF("GREEN OFF\r\n");
#endif
		break;
	case BLUE:
		PTD->PSOR = MASK(BLUE_LED_SHIFT);
#if DEBUG
		PRINTF("BLUE OFF\r\n");
#endif
		break;
	case ALL:
		PTB->PSOR = MASK(RED_LED_SHIFT);
		PTB->PSOR = MASK(GREEN_LED_SHIFT);
		PTD->PSOR = MASK(BLUE_LED_SHIFT);
#if DEBUG
		PRINTF("ALL OFF\r\n");
#endif
		break;
	default:
		PRINTF("ERROR\r\n");
	}
}
