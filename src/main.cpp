/*
  Firmware Name: .... dc-to-ac
  Author: ........... Scott Griffis
  Date: ............. 06/03/2025

  The only point of this firware is to enable an ATTiny45 to produce an AC 
  signal between 2 pins at about a rough 60 Hz. This is intended to replace 
  a Chineese chip that powers an LED tree. For some reason beyond my understanding
  they made the tree so that only an AC signal will light the LEDs. 
*/

#include <Arduino.h>

#define PIN_L1 2
#define PIN_L2 1

bool l1 = false;
bool l2 = true;

void setup() {
  pinMode(PIN_L1, OUTPUT);
  pinMode(PIN_L2, OUTPUT);

  digitalWrite(PIN_L1, l1 ? HIGH : LOW);
  digitalWrite(PIN_L2, l2 ? HIGH : LOW);
}

void loop() {
  digitalWrite(PIN_L1, ((l1 = !l1) ? HIGH : LOW));
  digitalWrite(PIN_L2, ((l2 = !l2) ? HIGH : LOW));
  delay(1L);
}
