#ifndef CTCH
#define CTCH

#include "CTC_DISPLAY.h"
#include "CTC_PINS.h"

void CTC_init()
{
    pinMode(LCD_CLK, OUTPUT);
    pinMode(LCD_DAT, OUTPUT);
    pinMode(LCD_STR, OUTPUT);
    
    lcd_init();

    
    pinMode(BUZZER, OUTPUT);

    pinMode(LED_DEBUG, OUTPUT);
    pinMode(LED_1, OUTPUT);
    pinMode(LED_2, OUTPUT);
    pinMode(LED_3, OUTPUT);

    pinMode(X_DIR, OUTPUT);
    pinMode(X_STP, OUTPUT);
    pinMode(X_EN, OUTPUT);

    pinMode(Y_DIR, OUTPUT);
    pinMode(Y_STP, OUTPUT);
    pinMode(Y_EN, OUTPUT);

    pinMode(Z_DIR, OUTPUT);
    pinMode(Z_STP, OUTPUT);
    pinMode(Z_EN, OUTPUT);

    pinMode(A_DIR, OUTPUT);
    pinMode(A_STP, OUTPUT);
    pinMode(A_EN, OUTPUT);

    pinMode(B_DIR, OUTPUT);
    pinMode(B_STP, OUTPUT);
    pinMode(B_EN, OUTPUT);

    pinMode(X_MIN, INPUT);
    pinMode(X_MAX, INPUT);
    pinMode(Y_MIN, INPUT);
    pinMode(Y_MAX, INPUT);
    pinMode(Z_MIN, INPUT);
    pinMode(Z_MAX, INPUT);

    //Set the inputs for the Buttons.
    // Since those are not connected on Arduino Mega, it has to happen via hardware registers.
    DDRJ = ~((~DDRJ) | B00011111);
}


void steps(char stepper, bool direction, int n)
{
  byte STP;
  byte DIR;
  if(stepper == 'A')
  {
    STP = A_STP;
    DIR = A_DIR;
  }
  else if(stepper == 'B')
  {
    STP = B_STP;
    DIR = B_DIR;
  }
  else if(stepper == 'X')
  {
    STP = X_STP;
    DIR = X_DIR;
  }
  else if(stepper == 'Y')
  {
    STP = Y_STP;
    DIR = Y_DIR;
  }
  else if(stepper == 'Z')
  {
    STP = Z_STP;
    DIR = Z_DIR;
  }

  digitalWrite(DIR, direction);
  for(int i = 0; i < n; i++)
  {
    digitalWrite(STP, HIGH);
    delayMicroseconds(200);
    digitalWrite(STP, LOW);
    delayMicroseconds(200);
  }
}

bool getButton(byte button)
{
  if(button == BTN_UP)
  {
    return (~PINJ) & B00010000;
  }
  else if(button == BTN_DOWN)
  {
    return (~PINJ) & B00001000;
  }
  else if(button == BTN_LEFT)
  {
    return (~PINJ) & B00000100;
  }
  else if(button == BTN_RIGHT)
  {
    return (~PINJ) & B00000010;
  }
  else if(button == BTN_M)
  {
    return (~PINJ) & B00000001;
  }

  return false;
}

bool getEndstop(byte endstop)
{
    return(!digitalRead(endstop));
}


#endif