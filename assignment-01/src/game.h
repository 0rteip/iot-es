/**
 * @file game.h
 * @brief This file contains the definition of game utils.
 */
#ifndef __GAME_H__
#define __GAME_H__

#define DIFF_LEVELS 4          // number of difficulty levels
#define BASE_DIFF_FACTOR 0.075 // base difficulty factor

#define GAME_INTRO 0
#define GAME_WAIT_START 1
#define GAME_INIT 2
#define GAME_GENERATE_SEQUENCE 3
#define GAME_PREP 4
#define GAME_SHOW_SEQUENCE 5
#define GAME_PLAYING 6
#define GAME_END 7
#define SLEEP 8

/**
 * Game introduction.
 */
void gameIntro();

/**
 * This function waits for the player to start the game.
 */
void gameWaitStart();

/**
 * This function is called when the game is initializing.
 */
void gameInit();

/**
 * This function is called when the game is generating the sequence.
 */
void gameGenerateSequence();

/**
 * This function is called when the game is preparing to play.
 */
void gamePrep();

/**
 * This function is called when the game is showing the sequence.
 */
void gameShowSequence();

/**
 * This function is called when the game is playing.
 */
void gamePlaying();

/**
 * This function is called when the game is over.
 */
void gameEnd();

/**
 * This function sets the current game status.
 *
 * @param status The new game status.
 */
void setGameStatus(int status);

/**
 * This function returns the current game status.
 *
 * @return int The current game status.
 */
int getGameStatus();

/**
 * This function checks if the difficultu level has changed.
 */
void checkDifficultyLevel();

/**
 * This function is called when the game go to sleep.
 */
void sleep();

#endif