#ifndef CTCPINSH
#define CTCPINSH

//The buttons are not pins, just enumerators for the function getButton()
//As the buttons are mapped to PORTJ they cannot be accesed by the arduino-specific pins
#define BTN_UP 0
#define BTN_DOWN 1
#define BTN_LEFT 2
#define BTN_RIGHT 3
#define BTN_M 4

//These are just directions mapped to 0 and 1 for better readability
#define CLOCKWISE 1
#define COUNTERCLOCKWISE 0

//These are all pins
#define LED_1 36
#define LED_2 37
#define LED_3 40
#define LED_DEBUG 13

#define X_DIR A0
#define X_STP A1
#define X_EN A2
#define X_POT A3

#define Y_DIR A4
#define Y_STP A5
#define Y_EN A6
#define Y_POT A7

#define Z_DIR A8
#define Z_STP A9
#define Z_EN A10
#define Z_POT A11

#define A_DIR 24
#define A_STP 25
#define A_EN 26
#define A_POT 27

#define B_DIR 28
#define B_STP 29
#define B_EN 39

#define X_MIN 49
#define X_MAX 48
#define Y_MIN 47
#define Y_MAX 46
#define Z_MIN 43
#define Z_MAX 42

#define LCD_CLK 35
#define LCD_DAT 34
#define LCD_STR 33

#define BUZZER 4

#endif