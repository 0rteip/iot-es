/**
 * @file buttons_controll.cpp
 * @brief This file contains buttons utils.
 */
#include <Arduino.h>
#include <EnableInterrupt.h>
#include "io_conf.h"
#include "buttons_controll.h"

int buttons[] = {BUTT_1, BUTT_2, BUTT_3, BUTT_4};
int buttonsPressed[BUTTS_NUMBER];
unsigned long lastIntTime[BUTTS_NUMBER];

int pressCounter = 0;
int pressSeq[BUTTS_NUMBER];

void buttonPressed1()
{
    buttonPressed(0);
}

void buttonPressed2()
{
    buttonPressed(1);
}

void buttonPressed3()
{
    buttonPressed(2);
}

void buttonPressed4()
{
    buttonPressed(3);
}

void (*buttonPressedFunctions[])(void) = {buttonPressed1, buttonPressed2, buttonPressed3, buttonPressed4};

void initButtons()
{
    for (int butt = 0; butt < BUTTS_NUMBER; butt++)
    {
        pinMode(buttons[butt], INPUT);
        enableInterrupt(buttons[butt], buttonPressedFunctions[butt], RISING);
    }
}

void buttonPressed(int butt)
{
    unsigned long intTime = millis();

    if (intTime - lastIntTime[butt] > DEBOUNCE_DELAY)
    {
        if (pressCounter < BUTTS_NUMBER && buttonsPressed[butt] == 0)
        {
            buttonsPressed[butt] = 1;
            pressSeq[pressCounter++] = butt;
        }
        lastIntTime[butt] = intTime;
    }
}

int hasStartButtonBeenPressed()
{
    return buttonsPressed[0];
}

int *getButtonsStatus()
{
    return buttonsPressed;
}

void restoreButtonsStatus()
{
    for (int butt = 0; butt < BUTTS_NUMBER; butt++)
    {
        buttonsPressed[butt] = 0;
        pressSeq[butt] = 0;
    }
    pressCounter = 0;
}

int areAllButtonsPressed()
{
    return pressCounter == BUTTS_NUMBER;
}

int *getPressSeq()
{
    return pressSeq;
}