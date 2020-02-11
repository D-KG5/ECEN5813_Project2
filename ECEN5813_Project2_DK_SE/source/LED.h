/*
 * LED.h
 *
 *  Created on: Feb 8, 2020
 *      Author: Dhruva
 */

#ifndef LED_H_
#define LED_H_

void Delay(volatile uint32_t number);
void LED_init(void);
void LED_on(uint8_t color);
void LED_off(uint8_t color);
void KL25Z_RGB_Flasher(void);

#endif /* LED_H_ */
