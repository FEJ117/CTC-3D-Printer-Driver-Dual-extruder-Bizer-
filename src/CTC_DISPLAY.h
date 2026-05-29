#ifndef CTCDISPLAYH
#define CTCDISPLAYH

#include "CTC_PINS.h"

void SR_write_bit(bool b)
{
  digitalWrite(LCD_DAT, b);
  delayMicroseconds(10);
  digitalWrite(LCD_CLK, HIGH);
  delayMicroseconds(10);
  digitalWrite(LCD_CLK, LOW);
  delayMicroseconds(10);
}

void SR_write_byte(byte b)
{
  for(int i = 7; i >= 0; i--)
  {
    SR_write_bit(b & (B00000001 << i));
  }

  digitalWrite(LCD_STR, HIGH);
  delayMicroseconds(10);
  digitalWrite(LCD_STR, LOW);
  delayMicroseconds(10);

}

void write_nibble(byte nibble, bool rs)
{
  byte byteToWrite = rs << 1;
  byteToWrite = byteToWrite | B00001000;
  byteToWrite = byteToWrite | (nibble << 4);
  SR_write_byte(byteToWrite);
  byteToWrite = byteToWrite ^ B00001000;
  SR_write_byte(byteToWrite);
}

void write_byte(byte nibbles, bool rs)
{
  write_nibble(nibbles >> 4, rs);
  write_nibble(nibbles & 0x0F, rs);
}

void lcd_init(void)
{

  pinMode(LCD_CLK, OUTPUT);
  pinMode(LCD_DAT, OUTPUT);
  pinMode(LCD_STR, OUTPUT);

 
  //shift_reset();


  delay(60);


  //--- LCD INIT (4-bit) ---
  write_nibble(0x03, 0); delay(5);
  write_nibble(0x03, 0); delayMicroseconds(150);
  write_nibble(0x03, 0);
  write_nibble(0x02, 0);

  write_byte(0x28, 0);  // 4-bit, 2-line (works for 4x20 too)
  write_byte(0x0C, 0);  // display ON
  write_byte(0x01, 0);  // clear
  delay(2);
  write_byte(0x06, 0);  // entry mode

}

void moveCursor(byte row, byte col)
{
  byte command;
  if(row == 0)
    command = 0x80 | (0x00 + col); // 0x80 + address
  else if(row == 1)
    command = 0x80 | (0x40 + col); // 0x80 + address
  else if(row == 2)
    command = 0x80 | (0x14 + col); // 0x80 + address
  else if(row == 3)
    command = 0x80 | (0x54 + col); // 0x80 + address
  else return;

  write_byte(command, 0);
}

void lcdPrintStringAt(byte row, byte col, const char *str)
{
  moveCursor(row, col);
  while (*str)
  {
    if(col < 20)
    col++;
    else
    {
      row++;
      if(row > 3)return;
      col = 0;
      moveCursor(row, col);
      col++;
    }
    write_byte(*str++, 1);   // RS = 1 → data
  }
}

void lcdPrintCharAt(byte row, byte col, char *ch)
{
  moveCursor(row, col);
  write_byte(ch, 1);
}

#endif