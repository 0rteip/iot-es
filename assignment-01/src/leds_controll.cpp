/**
 * @file leds_controll.cpp
 * @brief This file contains the definitions of led utils.
 */
#include <Arduino.h>
#include "io_conf.h"
#include "leds_controll.h"

// pulsing led variables
int mod = 1;
int intensity = 0;
unsigned long lastFade = 0;

// leds variables
int leds[] = {LED_1, LED_2, LED_3, LED_4};
int currLed = 0;

void initLed()
{
  for (int led = 0; led < LEDS_NUMBER; led++)
  {
    pinMode(leds[led], OUTPUT);
  }
  pinMode(LED_S, OUTPUT);
}

void turnAllGameLedOn()
{
  for (int led = 0; led < LEDS_NUMBER; led++)
  {
    digitalWrite(leds[led], HIGH);
  }
}

void turnAllOff()
{
  for (int led = 0; led < LEDS_NUMBER; led++)
  {
    digitalWrite(leds[led], LOW);
  }
  digitalWrite(LED_S, LOW);
}

void turnOffLed(int led)
{
  digitalWrite(leds[led], LOW);
}

void turnOnArray(int *ledsArray)
{
  for (int led = 0; led < LEDS_NUMBER; led++)
  {
    digitalWrite(leds[led], ledsArray[led]);
  }
}

void turnOnStatusLed()
{
  digitalWrite(LED_S, HIGH);
}

void turnOffStatusLed()
{
  digitalWrite(LED_S, LOW);
}

void fadeLed()
{
  unsigned long time = millis();

  if (time - lastFade > FADE_DELAY)
  {
    analogWrite(LED_S, intensity);
    intensity += mod;
    if (intensity == 255 || intensity == 0)
    {
      mod *= -1;
    }
    lastFade = time;
  }
}

void testLed()
{
  int i = 0;
  Serial.println("Test led");
  for (int led = 0; led < LEDS_NUMBER; led++)
  {
    digitalWrite(leds[led], HIGH);
    delay(250);
    digitalWrite(leds[led], LOW);
  }
  for (i = 0; i < 10; i++)
  {
    analogWrite(LED_S, i * 25);
    delay(10);
  }
  for (; i >= 0; i--)
  {
    analogWrite(LED_S, i * 25);
    delay(10);
  }
  Serial.println("End test led");
}
