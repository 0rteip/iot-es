/**
 * @file time_controll.h
 * @brief This file contains the declaration of time utils.
 */
#ifndef __TIME_CONTROLL__
#define __TIME_CONTROLL__

#define SEC_MILLIS 1000 // milliseconds
#define T_ONE 3000      // milliseconds - time leds are on
#define T_TWO 2000      // milliseconds - turning off time
#define T_THREE 6000    // milliseconds - player game time
#define T_RESTART 10000 // milliseconds - time to restart the game
#define T_MIN 100       // milliseconds - minimum turning off time

#ifndef __TEST__
#define T_SLEEP 10000 // milliseconds - time before sleep
#else
#define T_SLEEP 30000 // milliseconds - time before sleep
#endif

/**
 * Time initialization.
 */
void initTime();

/**
 * This functtion is called to increment the game time.
 */
void incrementGameTime();

/**
 * Get the game time.
 *
 * @return The game time.
 */
int getGameTime();

/**
 * Reset the game time.
 */
void resetGameTime();

#endif