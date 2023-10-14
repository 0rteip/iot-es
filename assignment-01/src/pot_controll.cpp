/**
 * @file pot_controll.c
 * @brief This file contains the implementation of potentiometer utils.
 */
#include <Arduino.h>
#include "pot_controll.h"
#include "io_conf.h"
#include "game.h"

void initPot()
{
    pinMode(POT, INPUT);
}

int getPotValue()
{
    return map(analogRead(POT), 0, 1023, 1, DIFF_LEVELS);
}
