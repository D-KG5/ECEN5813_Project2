/*
 * LED.c
 *
 *  Created on: Feb 8, 2020
 *      Author: Dhruva
 */
#include <stdio.h>
#include "board.h"
#include "MKL25Z4.h"

#include "LED.h"
#include "global_defines.h"

// delay function
void Delay(volatile uint32_t number){
	while(number != 0){
		__asm volatile("NOP");
		number--;
	}
}


// initialize RGB LEDs
void LED_init(void){
    // https://github.com/alexander-g-dean/ESF/blob/master/Code/Chapter_2/Source/main.c
	// start clock for PORT B and PORT D
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTD_MASK;

	// Make 3 pins GPIO
	PORTB->PCR[RED_LED_SHIFT] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[RED_LED_SHIFT] |= PORT_PCR_MUX(1);
	PORTB->PCR[GREEN_LED_SHIFT] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[GREEN_LED_SHIFT] |= PORT_PCR_MUX(1);
	PORTD->PCR[BLUE_LED_SHIFT] &= ~PORT_PCR_MUX_MASK;
	PORTD->PCR[BLUE_LED_SHIFT] |= PORT_PCR_MUX(1);

	// set ports to outputs
	PTB->PDDR |= MASK(RED_LED_SHIFT) | MASK(GREEN_LED_SHIFT);
	PTD->PDDR |= MASK(BLUE_LED_SHIFT);
	// clear ports
	PTB->PCOR |= MASK(RED_LED_SHIFT) | MASK(GREEN_LED_SHIFT);
	PTD->PCOR |= MASK(BLUE_LED_SHIFT);
}

/**
 * turn on LED by colour
 * @args unit8_t color: pass in desired color of RGB LED
 */
void LED_on(uint8_t color){
	// set RGB LED Pins
	switch(color){
	case RED:
		PTB->PCOR = MASK(RED_LED_SHIFT);
		PTB->PSOR = MASK(GREEN_LED_SHIFT);
		PTD->PSOR = MASK(BLUE_LED_SHIFT);
#if DEBUG
		printf("RED ON\r\n");
#endif
		break;
	case GREEN:
		PTB->PSOR = MASK(RED_LED_SHIFT);
		PTB->PCOR = MASK(GREEN_LED_SHIFT);
		PTD->PSOR = MASK(BLUE_LED_SHIFT);
#if DEBUG
		printf("GREEN ON\r\n");
#endif
		break;
	case BLUE:
		PTB->PSOR = MASK(RED_LED_SHIFT);
		PTB->PSOR = MASK(GREEN_LED_SHIFT);
		PTD->PCOR = MASK(BLUE_LED_SHIFT);
#if DEBUG
		printf("BLUE ON\r\n");
#endif
		break;
	case ALL:
		PTB->PCOR = MASK(RED_LED_SHIFT);
		PTB->PCOR = MASK(GREEN_LED_SHIFT);
		PTD->PCOR = MASK(BLUE_LED_SHIFT);
#if DEBUG
//		printf("ALL ON\r\n");
#endif
		break;
	default:
		printf("Error turning on LED\r\n");
	}
}

/**
 * turn off LED by colour
 * @args unit8_t color: pass in desired color of RGB LED
 */
void LED_off(uint8_t color){
	// clear RGB LED Pins
	switch(color){
	case RED:
		PTB->PSOR = MASK(RED_LED_SHIFT);
#if DEBUG
		printf("RED OFF\r\n");
#endif
		break;
	case GREEN:
		PTB->PSOR = MASK(GREEN_LED_SHIFT);
#if DEBUG
		printf("GREEN OFF\r\n");
#endif
		break;
	case BLUE:
		PTD->PSOR = MASK(BLUE_LED_SHIFT);
#if DEBUG
		printf("BLUE OFF\r\n");
#endif
		break;
	case ALL:
		PTB->PSOR = MASK(RED_LED_SHIFT);
		PTB->PSOR = MASK(GREEN_LED_SHIFT);
		PTD->PSOR = MASK(BLUE_LED_SHIFT);
#if DEBUG
//		printf("ALL OFF\r\n");
#endif
		break;
	default:
		printf("Error turning off LED\r\n");
	}
}

void KL25Z_RGB_Flasher(void)
{
	int num=0;


//	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTD_MASK;
//
//
//	PORTD->PCR[BLUE_LED_SHIFT] &= ~PORT_PCR_MUX_MASK;
//	PORTD->PCR[BLUE_LED_SHIFT] |= PORT_PCR_MUX(1);
//
//	PTD->PDDR |= MASK(BLUE_LED_SHIFT);
//	PTD->PCOR |= MASK(BLUE_LED_SHIFT);

	while(num<10)
	{



	PTD->PCOR = MASK(BLUE_LED_SHIFT);
	printf("LED is on\n");
	Delay(500000);

	PTD->PSOR = MASK(BLUE_LED_SHIFT);
	printf("LED is off\n");
	Delay(500000);


	PTD->PCOR = MASK(BLUE_LED_SHIFT);
	printf("LED is on\n");
	Delay(1000000);

	PTD->PSOR = MASK(BLUE_LED_SHIFT);
	printf("LED is off\n");
	Delay(500000);

	PTD->PCOR = MASK(BLUE_LED_SHIFT);
	printf("LED is on\n");
	Delay(2000000);


	PTD->PSOR = MASK(BLUE_LED_SHIFT);
	printf("LED is off\n");
	Delay(500000);


	PTD->PCOR = MASK(BLUE_LED_SHIFT);
	printf("LED is on\n");
	Delay(3000000);

	PTD->PSOR = MASK(BLUE_LED_SHIFT);
	printf("LED is off\n");
	Delay(500000);


	printf("loop %d complete\n",num+1);

	num=num+1;

	}


}

