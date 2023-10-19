/**
 * @file time_controll.h
 * @brief This file contains the declaration of time utils.
 */
#ifndef __TIME_CONTROLL__
#define __TIME_CONTROLL__

#define SEC 1000000               // microseconds
#define SEC_MILLIS 1000           // milliseconds
#define T_ONE 3 * SEC_MILLIS      // seconds - time to remain on
#define T_TWO 2 * SEC_MILLIS      // seconds - turning off time
#define T_THREE 10 * SEC_MILLIS   // seconds - player game time
#define T_RESTART 10 * SEC_MILLIS // seconds - time to restart the game

#ifdef __TEST__
#define T_SLEEP 30 * SEC_MILLIS // seconds - time before sleep
#else
#define T_SLEEP 10 * SEC_MILLIS   // seconds - time before sleep
#endif

/**
 * Time initialization.
 */
void initTime();

/**
 * This functtion is called every second to increment the game time.
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