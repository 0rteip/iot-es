/**
 * @file pot_controll.h
 * @brief This file contains the declaration of potentiometer utils.
 */
#ifndef __POT_CONTROLL__
#define __POT_CONTROLL__

/**
 * Potentiometer initialization.
 */
void initPot();

/**
 * Get the potentiometer value.
 *
 * @return The potentiometer value from 1 to 4.
 */
int getPotValue();

#endif