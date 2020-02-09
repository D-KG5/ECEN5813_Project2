/*
 * Touch.c
 *
 *  Created on: Feb 9, 2020
 *      Author: Dhruva
 */
#include <stdio.h>
#include "board.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"

#include "Touch.h"
#include "LED.h"
#include "def.h"

// initialize slider
// https://www.digikey.com/eewiki/display/microcontroller/Using+the+Capacitive+Touch+Sensor+on+the+FRDM-KL46Z
void Touch_init(void){
	// Enable clock for TSI PortB 16 and 17
	SIM->SCGC5 |= SIM_SCGC5_TSI_MASK;

	TSI0->GENCS = TSI_GENCS_OUTRGF_MASK |  // Out of range flag, set to 1 to clear
		//TSI_GENCS_ESOR_MASK |  // This is disabled to give an interrupt when out of range.  Enable to give an interrupt when end of scan
		TSI_GENCS_MODE(0u) |  // Set at 0 for capacitive sensing.  Other settings are 4 and 8 for threshold detection, and 12 for noise detection
		TSI_GENCS_REFCHRG(0u) | // 0-7 for Reference charge
		TSI_GENCS_DVOLT(0u) | // 0-3 sets the Voltage range
		TSI_GENCS_EXTCHRG(0u) | //0-7 for External charge
		TSI_GENCS_PS(0u) | // 0-7 for electrode prescaler
		TSI_GENCS_NSCN(31u) | // 0-31 + 1 for number of scans per electrode
		TSI_GENCS_TSIEN_MASK | // TSI enable bit
		//TSI_GENCS_TSIIEN_MASK | //TSI interrupt is disables
		TSI_GENCS_STPE_MASK | // Enables TSI in low power mode
		//TSI_GENCS_STM_MASK | // 0 for software trigger, 1 for hardware trigger
		//TSI_GENCS_SCNIP_MASK | // scan in progress flag
		TSI_GENCS_EOSF_MASK ; // End of scan flag, set to 1 to clear
		//TSI_GENCS_CURSW_MASK; // Do not swap current sources
}

// start slider scan
uint16_t Touch_scan(void){
	int scan;
	TSI0->DATA = 	TSI_DATA_TSICH(9u); // Using channel 9 of the TSI
	TSI0->DATA |= TSI_DATA_SWTS_MASK; // Software trigger for scan
	scan = SCAN_DATA;
	TSI0->GENCS |= TSI_GENCS_EOSF_MASK ; // Reset end of scan flag
	return scan - SCAN_OFFSET;
}

// set colour of LED based on value of slider
uint8_t Set_colour(void){
	uint16_t val;
	uint8_t colour = 0;
	val = Touch_scan();
#if DEBUG
	PRINTF("SLIDER VALUE %d\r\n", val);
#endif
	if(val <= 30){
		LED_off(ALL);
		colour = ALL;
	} else if((val > 30) && (val <= 600)){
		//red
		LED_off(ALL);
		colour = RED;
	} else if((val > 600) && (val <= 1400)){
		//green
		LED_off(ALL);
		colour = GREEN;
	} else if((val > 1400)){
		//blue
		LED_off(ALL);
		colour = BLUE;
	} else{
		// error
		LED_off(ALL);
		colour = 0;
		PRINTF("Error: Slider Value: %d is out of bounds\r\n", val);
	}
	return colour;
}

