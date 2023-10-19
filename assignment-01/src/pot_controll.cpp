/**
 * @file pot_controll.c
 * @brief This file contains the implementation of potentiometer utils.
 */
#include <Arduino.h>
#include "pot_controll.h"
#include "io_conf.h"
#include "game.h"

#define DELAY_TIME 120

int potValue;
int lastReadPotValue;

int getValue();

void initPot()
{
    pinMode(POT, INPUT);
    potValue = getValue();
}

int getPotValue()
{
    unsigned long potTime = millis();
    
    if (potTime - lastReadPotValue > DELAY_TIME)
    {
        potValue = getValue();
        lastReadPotValue = potTime;
    }

    return potValue;
}

int getValue() {
    // Use of map() with maximum value 1024 to improve precision
    return map(analogRead(POT), 0, 1024, 1, DIFF_LEVELS + 1);
}