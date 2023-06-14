#include <Arduino.h>

// Arduino pins and their corresponding connection to the Texas Instruments SN74HC595 IC
#define SR_DATA 2  // to pin 14 of 'HC595
#define SR_CLOCK 3 // to pin 11 of 'HC595
#define SR_LATCH 4 // to pin 12 of 'HC595
//#define SR_OE A5   // to pin 13 of 'HC595

void shift_register_write_byte(uint8_t byte_value);

void setup() {
  pinMode(SR_DATA, OUTPUT);
  pinMode(SR_CLOCK, OUTPUT);
  pinMode(SR_LATCH, OUTPUT);
  //pinMode(SR_OE, OUTPUT);

  shift_register_write_byte(0x55);
  delay(1500);
  shift_register_write_byte(0xAA);
  delay(1500);
  shift_register_write_byte(0x0F);
  delay(1500);
  shift_register_write_byte(0xF0);
  delay(1500);
  shift_register_write_byte(0xFF);
  delay(1500);

  for(int i = 0; i < 256; i++)
  {
    shift_register_write_byte(i);
    delay(100);
  }
}

void loop() {
  // don't need to do anything more after the first test in setup()
}

void shift_register_write_byte(uint8_t byte_value)
{
  shiftOut(SR_DATA, SR_CLOCK, LSBFIRST, byte_value); // send 8 bit number to 'HC595' shift register
  digitalWrite(SR_LATCH, HIGH); // toggle 'HC595's latch so we can
  digitalWrite(SR_LATCH, LOW); // actually see the internal value
}