/**
 * @file main.cpp
 * @brief This file contains the main program.
 *
 * @author Pietro Ventrucci
 */
#include <Arduino.h>
#include "time_controll.h"
#include "game.h"
#include "leds_controll.h"
#include "buttons_controll.h"
#include "pot_controll.h"

void setup()
{
    initLed();
    initButtons();
    initPot();

    Serial.begin(9600);

    testLed();
}

void loop()
{
    incrementGameTime();
    switch (getGameStatus())
    {
    case GAME_INTRO:
        gameIntro();
        break;
    case GAME_WAIT_START:
        gameWaitStart();
        break;
    case GAME_INIT:
        gameInit();
        break;
    case GAME_GENERATE_SEQUENCE:
        gameGenerateSequence();
        break;
    case GAME_PREP:
        gamePrep();
        break;
    case GAME_SHOW_SEQUENCE:
        gameShowSequence();
        break;
    case GAME_PLAYING:
        gamePlaying();
        break;
    case SLEEP:
        sleep();
        break;
    case GAME_END:
        gameEnd();
        break;
    default:
        break;
    }
}
