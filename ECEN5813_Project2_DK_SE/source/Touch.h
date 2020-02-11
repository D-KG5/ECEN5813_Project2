/*
 * Touch.h
 *
 *  Created on: Feb 9, 2020
 *      Author: Dhruva
 */

#ifndef TOUCH_H_
#define TOUCH_H_

#define SCAN_OFFSET 544
#define SCAN_DATA TSI0->DATA & 0xFFFF


void Touch_init(void);
uint16_t Touch_scan(void);
uint8_t Set_colour(void);

#endif /* TOUCH_H_ */
