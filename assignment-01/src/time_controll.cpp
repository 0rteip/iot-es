/**
 * @file time_controll.cpp
 * @brief This file contains the implementation of time utils.
 */
#include <Arduino.h>
#include "time_controll.h"

unsigned long gameTime;
unsigned long enterTime;

void initTime()
{
    gameTime = 0;
    enterTime = millis();
}

void incrementGameTime()
{
    gameTime = millis() - enterTime;
}

int getGameTime()
{
    return gameTime;
}

void resetGameTime()
{
    gameTime = 0;
    enterTime = millis();
}
