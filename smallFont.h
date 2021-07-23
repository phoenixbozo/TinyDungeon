#pragma once

#include <Arduino.h>

// Small 3x5 charachter font - ok, it's 4x8 ;)
// Modified ASCII-like code page: '0'-'9','!?','A'-'Z' and some alien/UFO parts :)
const uint8_t  characterFont3x5[] PROGMEM = {
  // 0
  0b00111100,
  0b00100010,
  0b00011110,
  0b00000000,
  // 1
  0b00000000,
  0b00111110,
  0b00000000,
  0b00000000,
  // 2
  0b00111010,
  0b00101010,
  0b00101110,
  0b00000000,
  // 3
  0b00100010,
  0b00101010,
  0b00111110,
  0b00000000,
  // 4
  0b00001110,
  0b00001000,
  0b00111100,
  0b00000000,
  // 5
  0b00101110,
  0b00101010,
  0b00111010,
  0b00000000,
  // 6
  0b00111110,
  0b00101000,
  0b00111000,
  0b00000000,
  // 7
  0b00000010,
  0b00110010,
  0b00001110,
  0b00000000,
  // 8
  0b00111110,
  0b00101010,
  0b00111110,
  0b00000000,
  // 9
  0b00001110,
  0b00001010,
  0b00111110,
  0b00000000,
  // ':' - E (compass)
  0b00111110,
  0b00101010,
  0b00100010,
  0b00000000,
  // ';' - N (compass)
  0b00111110,
  0b00011100,
  0b00111110,
  0b00000000,
  // '<' - S (compass)
  0b00100100,
  0b00101010,
  0b00010010,
  0b00000000,
  // '=' - W (compass)
  0b00111110,
  0b00011000,
  0b00111110,
  0b00000000,
  // '>' - ?
  0b00000010,
  0b00101010,
  0b00001110,
  0b00000000,
 };
