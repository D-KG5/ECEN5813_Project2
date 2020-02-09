/*
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    ECEN5813_Project2_DK_SE.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */
#include "LED.h"
#include "Touch.h"
#include "def.h"
/* TODO: insert other definitions and declarations here. */

// delay function
static void Delay(volatile uint32_t number){
	while(number != 0){
		__asm volatile("NOP");
		number--;
	}
}

// lookup table function for delay
// 0=0, 1=500, 2=1000, 3=2000, 4=3000 ms
uint32_t Delay_update(uint32_t delay){
	static const uint32_t lookup[5] = {0, 1500000, 3000000, 6000000, 9000000};
	delay = lookup[delay];
#if DEBUG
	switch(delay){
	case 9000000:
		PRINTF("START TIMER 3000\r\n");
		break;
	case 6000000:
		PRINTF("START TIMER 2000\r\n");
		break;
	case 3000000:
		PRINTF("START TIMER 1000\r\n");
		break;
	case 1500000:
		PRINTF("START TIMER 500\r\n");
		break;
	case 0:
		PRINTF("START TIMER 0\r\n");
		break;
	default:
		PRINTF("Error starting timer\r\n");
		break;
	}
#endif
	return delay;
}

/*
 * @brief   Application entry point.
 */
int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();

#ifdef FBRUN
    PRINTF("Hello World FBRUN\r\n");
    // initialize RGB LED and Touch slider
    LED_init();
    Touch_init();

	for(int i = 0; i < 10; i++){
		// 500ms on, 500ms off
		LED_on(Set_colour());
		Delay(Delay_update(1));
		LED_off(Set_colour());
		Delay(Delay_update(1));
		// 1000ms on, 500ms off
		LED_on(Set_colour());
		Delay(Delay_update(2));
		LED_off(Set_colour());
		Delay(Delay_update(1));
		// 2000ms on, 500ms off
		LED_on(Set_colour());
		Delay(Delay_update(3));
		LED_off(Set_colour());
		Delay(Delay_update(1));
		// 30000ms on, 500ms off
		LED_on(Set_colour());
		Delay(Delay_update(4));
		LED_off(Set_colour());
		Delay(Delay_update(1));
	}
#if DEBUG
	PRINTF("10 cycles done\r\n");
#endif
    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
        i++ ;
        /* 'Dummy' NOP to allow source level single stepping of
            tight while() loop */
        __asm volatile ("nop");
    }
#endif
#ifdef PCRUN
    PRINTF("Hello World\n");
    PRINTF("Hello World PCRUN\n");

    /* Force the counter to be placed into memory. */
    volatile static int j = 0 ;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
        j++ ;
        /* 'Dummy' NOP to allow source level single stepping of
            tight while() loop */
        __asm volatile ("nop");
    }
#endif
    return 0 ;
}
