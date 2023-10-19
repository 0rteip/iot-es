/**
 * @file game.cpp
 * @brief This file contains the implementation of game utils.
 */
#include <Arduino.h>
#include <avr/sleep.h>
#include <time.h>
#include "leds_controll.h"
#include "time_controll.h"
#include "io_conf.h"
#include "buttons_controll.h"
#include "pot_controll.h"
#include "game.h"

int gameScore;
int gameDiff;
int gameStatus = GAME_INTRO;

int seqCounter;
int sequence[BUTTS_NUMBER];

float reducingTime;

void generateSquence();

void gameResult();

void gameIntro()
{
    turnAllOff();
    fadeLed();
    restoreButtonsStatus();
    gameDiff = 0;
    Serial.println("Welcome to the Restore the Light Game. Press Key B1 to Start");

    initTime();
    setGameStatus(GAME_WAIT_START);
}

void gameWaitStart()
{
    if (getGameTime() >= T_SLEEP)
    {
        setGameStatus(SLEEP);
    }
    if (hasStartButtonBeenPressed())
    {
        gameScore = 0;
        reducingTime = 0;
        setGameStatus(GAME_INIT);
    }
    checkDifficultyLevel();
    fadeLed();
}

void gameInit()
{
    turnAllOff();
    setGameStatus(GAME_GENERATE_SEQUENCE);
}

void gameGenerateSequence()
{
    generateSquence();
    setGameStatus(GAME_PREP);
    turnAllGameLedOn();
}

void gamePrep()
{
    if (getGameTime() >= T_ONE)
    {
        seqCounter = 0;
        setGameStatus(GAME_SHOW_SEQUENCE);
    }
}

void gameShowSequence()
{
    if (getGameTime() >= T_TWO - reducingTime * SEC_MILLIS)
    {
        turnOffLed(sequence[seqCounter++]);
        resetGameTime();
        if (seqCounter == BUTTS_NUMBER)
        {
            restoreButtonsStatus();
            setGameStatus(GAME_PLAYING);
            Serial.println("Go!");
        }
    }
}

void gamePlaying()
{
    turnOnArray(getButtonsStatus());

    if (areAllButtonsPressed() || getGameTime() >= T_THREE - reducingTime * SEC_MILLIS)
    {
        gameResult();
    }
}

void gameEnd()
{
    if (getGameTime() >= T_RESTART)
    {
        setGameStatus(GAME_INTRO);
    }
}

void gameResult()
{
    int *pressSeq = getPressSeq();
    int end = 0;
    for (int i = 0; i < BUTTS_NUMBER; i++)
    {
        if (pressSeq[BUTTS_NUMBER - 1 - i] != sequence[i])
        {
            turnAllOff();
            turnOnStatusLed();
            delay(SEC_MILLIS);
            turnOffStatusLed();
            Serial.print("Game Over. Final Score: ");
            setGameStatus(GAME_END);
            end = 1;
            break;
        }
    }
    if (!end)
    {
        gameScore++;
        reducingTime = gameScore * BASE_DIFF_FACTOR * gameDiff;
        Serial.print("New point! Score: ");
        setGameStatus(GAME_INIT);
    }
    Serial.println(gameScore);
}

void setGameStatus(int status)
{
    resetGameTime();
    gameStatus = status;
}

int getGameStatus()
{
    return gameStatus;
}

void checkDifficultyLevel()
{
    int diff = getPotValue();
    if (gameDiff != diff)
    {
        gameDiff = diff;
        Serial.println("Difficulty: " + String(gameDiff));
    }
}

void sleep()
{
    Serial.println("Going to sleep...");
    turnAllOff();
    delay(0.5 * SEC_MILLIS);
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sleep_mode(); // go to sleep
    sleep_disable();
    setGameStatus(GAME_INTRO);
}

void generateSquence()
{
    if (!gameScore)
    {
        for (int i = 0; i < BUTTS_NUMBER; i++)
        {
            sequence[i] = i;
        }
        srand(time(NULL));
    }
    for (int i = BUTTS_NUMBER - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = sequence[i];
        sequence[i] = sequence[j];
        sequence[j] = temp;
    }
}