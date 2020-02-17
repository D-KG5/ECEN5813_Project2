# ECEN5813_Project2
PES Project 2 for ECEN 5813. By Dhruva Koley and Sagar Eligar

# Contents
- ECEN5813_Project2_DK_SE
  - source
    - ECEN5813_Project2_DK_SE.c: main source file containing LED flashing routines for FBRUN, FBDEBUG< PCRUN, PCDEBUG
    - LED.c: source file containing functions for LED flashing
    - LED.h: header file for LED.c
    - Touch.c: source file containing functions for capacitive touch sensor
    - Touch.h: header file for Touch.c
    - global_defines.h: header files holding macros used across LED, Touch, ECEN5813_Project2_DK_S source files as well as mode macros
- updated work breakdown structure

# Comments
For FBRUN and FBDEBUG, when the touch sensor is released, the program will flash the LED using the last known LED colour state (bit buggy depending on how much of your finger is touching the sensor).
Use macros in global_defines.h to control modes and debug printing
QR code on board is left

# Environment
 - Windows 10
 - MCUXpresso v11.1.0
