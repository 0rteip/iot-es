/**
 * @file leds_controll.h
 * @brief This file contains the declaration of led utils.
 */
#ifndef __LEDS_CONTROLL__
#define __LEDS_CONTROLL__

#define FADE_DELAY 2 // in ms

/**
 * Led initialization.
 */
void initLed();

/**
 * Turn on all the game leds.
 */
void turnAllGameLedOn();

/**
 * Turn off all the leds.
 */
void turnAllOff();

/**
 * Turn off single led.
*/
void turnOffLed(int led);

/**
 * Turn on led based on an array.
*/
void turnOnArray(int *leds);

/**
 * Turn on status led.
 */
void turnOnStatusLed();

/**
 * Turn off status led.
 */
void turnOffStatusLed();

/**
 * LED_S fading.
 */
void fadeLed();

/**
 * Led test.
 */
void testLed();

#endif