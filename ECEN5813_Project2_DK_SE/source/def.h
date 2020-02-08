/*
 * def.h
 *
 *  Created on: Feb 8, 2020
 *      Author: Dhruva
 */

#ifndef DEF_H_
#define DEF_H_

// macros to enable disable debug, FB, PC modes
#define FBRUN
#define PCRUN
#define DEBUG 1

// define macros for LED_init function
#define RED_LED_SHIFT   (18)	// on port B
#define GREEN_LED_SHIFT (19)	// on port B
#define BLUE_LED_SHIFT  (1)		// on port D
#define MASK(x) (1UL << (x))

// define macros for LED_on and LED_off functions
#define RED 1U
#define GREEN 2U
#define BLUE 3U
#define ALL 4U

#endif /* DEF_H_ */
