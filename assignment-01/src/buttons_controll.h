/**
 * @file buttons_controll.h
 * @brief This file contains the declaration of buttons utils.
 */
#ifndef __BUTTONS_CONTROLL__
#define __BUTTONS_CONTROLL__

/**
 * Buttons initialization.
 */
void initButtons();

/**
 * Check if start button has been pressed.
 *
 * @return 1 if pressed, 0 otherwise.
 */
int hasStartButtonBeenPressed();

/**
 * Button pressed callback.
 *
 * @param butt The button pressed.
 */
void buttonPressed(int butt);

/**
 * Get the buttons pressed.
 *
 * @return The buttons pressed array.
 */
int *getButtonsStatus();

/**
 * Restore buttons status.
 */
void restoreButtonsStatus();

/**
 * Check if all the buttons have been pressed.
 *
 * @return 1 if all pressed, 0 otherwise.
 */
int areAllButtonsPressed();

/**
 * Get the press sequence.
 *
 * @return The press sequence.
 */
int *getPressSeq();

#endif