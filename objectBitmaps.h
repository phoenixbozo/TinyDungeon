#pragma once

#include <Arduino.h>

// 'Title32x64', 32x64px (256 bytes)
const unsigned char statusPane [] PROGMEM = {
	0x00, 0x00, 0x08, 0x04, 0x04, 0x08, 0x10, 0x10, 0x08, 0x04, 0x04, 0x08, 0x14, 0x3e, 0x22, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x22, 0x3e, 0x14, 0x08, 0x04, 0x04, 0x08, 0x10, 0x10, 0x08, 0x04, 0x04, 
	0x00, 0x00, 0x01, 0x01, 0x7f, 0x01, 0x75, 0x01, 0x79, 0x08, 0x71, 0x01, 0x79, 0x40, 0xf9, 0x01, 
	0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 
	0x00, 0x00, 0x21, 0xa1, 0x3f, 0xa1, 0xa1, 0x1e, 0x80, 0x9c, 0x20, 0xbd, 0x81, 0xbd, 0x05, 0xb8, 
	0x80, 0x98, 0xa4, 0x7c, 0x00, 0x38, 0x54, 0x58, 0x00, 0x3c, 0x44, 0x78, 0x00, 0x7c, 0x04, 0x78, 
	0x00, 0xb8, 0x44, 0xa8, 0x14, 0x14, 0x14, 0x08, 0x14, 0x14, 0x14, 0x08, 0x14, 0x14, 0x14, 0x14, 
	0x08, 0x14, 0x14, 0x14, 0x14, 0x08, 0x14, 0x14, 0x14, 0x14, 0x08, 0x14, 0x14, 0xe4, 0x14, 0xe8, 
	0x00, 0xf7, 0x08, 0xf7, 0x00, 0x00, 0x3e, 0x08, 0x3e, 0x00, 0x3e, 0x0a, 0x0e, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbd, 0x42, 0xbd, 
	0x00, 0xde, 0x21, 0xde, 0x00, 0x00, 0x1e, 0x12, 0x0c, 0x00, 0x1c, 0x0a, 0x1c, 0x00, 0x1e, 0x04, 
	0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbb, 0x44, 0xbb, 
	0x00, 0xfb, 0x04, 0xfb, 0x00, 0x00, 0x0c, 0x12, 0x12, 0x0c, 0x0c, 0x1c, 0x0c, 0x1c, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf7, 0x08, 0xf7, 
	0x00, 0x5e, 0xa1, 0x9e, 0xa0, 0xa0, 0x40, 0xa0, 0xa0, 0xa0, 0x40, 0xa0, 0xa0, 0xa0, 0x40, 0xa0, 
	0xa0, 0xa0, 0x40, 0xa0, 0xa0, 0xa0, 0xa0, 0x40, 0xa0, 0xa0, 0xa0, 0x40, 0xa0, 0x9e, 0xa1, 0x5e
};

// 'new_bars_28x48_w_mask', 56x48px (336 bytes)
const unsigned char newBars [] PROGMEM = {
	0x00, 0xfe, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0x00, 
	0x00, 0x00, 0x00, 0xfe, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0x00, 0x01, 0x00, 0x00, 0x01, 
	0x7f, 0x7f, 0x01, 0x00, 0x00, 0x01, 0x7f, 0x7f, 0x01, 0x00, 0x00, 0x01, 0x7f, 0x7f, 0x01, 0x00, 
	0x00, 0x01, 0x7f, 0x7f, 0x01, 0x00, 0x00, 0x01, 0x00, 0xff, 0xff, 0x03, 0x03, 0x03, 0x03, 0xff, 
	0xff, 0x03, 0x03, 0x03, 0x03, 0xff, 0xff, 0x03, 0x03, 0x03, 0x03, 0xff, 0xff, 0x03, 0x03, 0x03, 
	0x03, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 
	0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 
	0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 
	0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 
	0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 
	0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 
	0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0xff, 0xff, 0x80, 
	0x80, 0x80, 0x80, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x00, 0x00, 
	0x00, 0x00, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x01, 0x01, 0x01, 0x01, 0x3f, 
	0x3f, 0x01, 0x01, 0x01, 0x01, 0x3f, 0x3f, 0x01, 0x01, 0x01, 0x01, 0x3f, 0x3f, 0x01, 0x01, 0x01, 
	0x01, 0x3f, 0x3f, 0x00, 0xc0, 0x80, 0x80, 0xc0, 0xfc, 0xfc, 0xc0, 0x80, 0x80, 0xc0, 0xfc, 0xfc, 
	0xc0, 0x80, 0x80, 0xc0, 0xfc, 0xfc, 0xc0, 0x80, 0x80, 0xc0, 0xfc, 0xfc, 0xc0, 0x80, 0x80, 0xc0
};

// 'door_32x56_w_mask', 64x56px (448 bytes)
const unsigned char door [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0xa0, 0xa0, 0x10, 0xc0, 0xd0, 0xe8, 0x00, 0xe8, 0xec, 0xe6, 
	0x0c, 0xea, 0xec, 0xe8, 0x00, 0xe8, 0xd0, 0xc0, 0x10, 0xa0, 0xa0, 0x40, 0x80, 0x00, 0x00, 0x00, 
	0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x01, 0x00, 
	0x01, 0x00, 0x01, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07, 0x0f, 0x0f, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 
	0x00, 0x00, 0x00, 0xc5, 0x00, 0xd7, 0xc7, 0xef, 0x02, 0xff, 0xff, 0xff, 0x10, 0xff, 0xff, 0xff, 
	0x01, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xf7, 0x00, 0x00, 
	0xff, 0xc7, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
	0x00, 0x00, 0x00, 0xb8, 0x00, 0xfa, 0xf8, 0xfd, 0x80, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 
	0x10, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x04, 0xff, 0xff, 0xff, 0x00, 0xde, 0x01, 0x00, 
	0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 
	0x00, 0x00, 0x00, 0x7b, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x08, 0xff, 0xff, 0xff, 
	0x00, 0xff, 0xff, 0xff, 0x0f, 0xf9, 0xf9, 0xf9, 0x99, 0xe1, 0xe1, 0xff, 0x00, 0x7b, 0x80, 0x00, 
	0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 
	0x00, 0x00, 0x00, 0x37, 0x00, 0xbf, 0x3f, 0x7f, 0x04, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 
	0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x77, 0x80, 0x00, 
	0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 
	0x00, 0x00, 0x00, 0x46, 0x00, 0xd6, 0xc6, 0xef, 0x40, 0xff, 0xff, 0xff, 0x01, 0xff, 0xff, 0xff, 
	0x10, 0xff, 0xff, 0xff, 0x01, 0xff, 0xff, 0xff, 0x08, 0xff, 0xff, 0xff, 0x00, 0x77, 0x00, 0x00, 
	0xff, 0xc6, 0x82, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
	0x00, 0x00, 0x00, 0x07, 0x08, 0x0d, 0x0d, 0x0d, 0x0c, 0x0d, 0x01, 0x0d, 0x0c, 0x0d, 0x0d, 0x0d, 
	0x00, 0x0d, 0x0d, 0x0d, 0x0e, 0x0d, 0x01, 0x0d, 0x0c, 0x0d, 0x0d, 0x0d, 0x08, 0x07, 0x00, 0x00, 
	0xff, 0xff, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 
	0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xff
};

// 'leverLeft 16x8_w_mask', 32x8px (24 bytes)
const unsigned char leverLeft [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'leverRight 16x8_w_mask', 32x8px (24 bytes)
const unsigned char leverRight [] PROGMEM = {
	0x00, 0x00, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/*
// 'leverDown_32x24_w_mask', 32x24px (96 bytes)
const unsigned char leverDown [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0xfc, 0x3c, 0x0c, 0x0c, 0x0c, 0x0c, 0x3c, 0xfc, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 
  0x00, 0x00, 0x00, 0x00, 0x3f, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x3f, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 
  0x00, 0x00, 0x00, 0x7c, 0x44, 0x44, 0x40, 0x40, 0x40, 0x40, 0x44, 0x44, 0x7c, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0x83, 0x83, 0x83, 0x80, 0x80, 0x80, 0x80, 0x83, 0x83, 0x83, 0xff, 0xff, 0xff
};

// 'leverUp_32x24_w_mask', 32x24px (96 bytes)
const unsigned char leverUp [] PROGMEM = {
  0x00, 0x00, 0x00, 0x3e, 0x22, 0x22, 0x02, 0x02, 0x02, 0x02, 0x22, 0x22, 0x3e, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xc1, 0xc1, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xc1, 0xc1, 0xff, 0xff, 0xff, 
  0x00, 0x00, 0x00, 0x00, 0xfc, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x3c, 0xfc, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 
  0x00, 0x00, 0x00, 0x00, 0x3f, 0x3c, 0x30, 0x30, 0x30, 0x30, 0x3c, 0x3f, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff
};
*/

// 'chest24x24_closed_v3_w_mask', 48x24px (144 bytes)
const unsigned char chestClosed [] PROGMEM = {
	0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
	0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0xff, 0x7f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
	0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x7f, 0xff, 0xff, 
	0x00, 0x77, 0x56, 0x76, 0x76, 0x76, 0x76, 0x76, 0x76, 0x86, 0x06, 0x66, 0x06, 0x86, 0x76, 0x76, 
	0x76, 0x76, 0x76, 0x76, 0x56, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
	0x00, 0x77, 0x55, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x76, 0x76, 0x76, 0x77, 0x77, 0x77, 
	0x77, 0x77, 0x77, 0x77, 0x55, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff
};

// 'chest24x24_open_w_mask', 48x24px (144 bytes)
const unsigned char chestOpen [] PROGMEM = {
	0x00, 0x00, 0x00, 0xfe, 0xb6, 0xb6, 0xb6, 0xb6, 0xb6, 0xb6, 0xb6, 0xb6, 0xb6, 0xb6, 0xb6, 0xb6, 
	0xb6, 0xb6, 0xb6, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 
	0x00, 0x70, 0x50, 0x75, 0x71, 0x75, 0x71, 0x75, 0x71, 0x75, 0xf1, 0x35, 0x31, 0xf5, 0x71, 0x75, 
	0x71, 0x75, 0x71, 0x75, 0x50, 0x70, 0x00, 0x00, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0xff, 
	0x00, 0x77, 0x55, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x76, 0x76, 0x77, 0x77, 0x77, 
	0x77, 0x77, 0x77, 0x77, 0x55, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff
};

// 'fountain_12x24_w_mask', 24x24px (72 bytes)
const unsigned char fountain [] PROGMEM = {
	0x00, 0x00, 0x60, 0x10, 0x30, 0x24, 0xfc, 0x24, 0x30, 0x10, 0x60, 0x00, 0xff, 0x9f, 0x0f, 0x87, 
	0x83, 0x01, 0x01, 0x01, 0x83, 0x87, 0x0f, 0x9f, 0x00, 0x00, 0x0c, 0x34, 0x6a, 0xe8, 0x0f, 0xe8, 
	0x6a, 0x34, 0x0c, 0x00, 0xff, 0xf3, 0xc1, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0xc1, 0xf3, 
	0x00, 0x00, 0x00, 0x10, 0x38, 0x2f, 0x20, 0x2f, 0x38, 0x10, 0x00, 0x00, 0xff, 0xff, 0xef, 0xc7, 
	0x80, 0x80, 0x80, 0x80, 0x80, 0xc7, 0xef, 0xff
};
