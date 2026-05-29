#include "Arduino.h"
#include "CTC.h"

//Examples for all provided functions
//Steppers are: 'A', 'B', 'X', 'Y', 'Z'
//Endstops are: X_MIN, X_MAX, Y_MIN, Y_MAX, Z_MIN, Z_MAX
//LEDs are: LED_1, LED_2, LED_3, LED_DEBUG
//Buzzer is: BUZZER and can be used like: tone(BUZZER, 100); //sounds horrible

void setup() {

  Serial.begin(9600);
  CTC_init();

  lcdPrintStringAt(0,0,"Hello");

  lcdPrintCharAt(1,0,'A');

  
}

void loop() {

  if(getButton(BTN_UP))
  {
    steps('A', CLOCKWISE, 10);
  }  

  if(getEndstop(X_MIN))
  {
    digitalWrite(LED_1, HIGH);
  }
  else
  {
    digitalWrite(LED_1, LOW);
  }
  
}


