//   >>>>>  T-I-N-Y  D-U-N-G-E-O-N v0.1 for ATTINY85  GPLv3 <<<<
//						Tinyjoypad rev2 compatible
//                   Programmer: Sven B 2021
//              Contact EMAIL: 

// The code works at 16MHZ internal
// and uses ssd1306xled Library for SSD1306 oled display 128x64.
//
// To stuff all code and data into the 8192 bytes of the ATtiny85
// the ATTinyCore (v1.5.2) by Spence Konde is recommended.
// The core is available at github: [https://github.com/SpenceKonde/ATTinyCore], just add the
// following board manager to the Arduino IDE: [http://drazzy.com/package_drazzy.com_index.json]
// Please enable LTO (link time optimization) and disable 'millis()' and
// 'micros()'.

// show an 8x8 grid overlay
//#define _SHOW_GRID_OVERLAY

#if defined(__AVR_ATtiny85__)
  #include <ssd1306xled.h>
#else
  #include "SerialHexTools.h"
  #include <Adafruit_SSD1306.h>
  Adafruit_SSD1306 display( 128, 64, &Wire, -1 );
#endif
#include "dungeon.h"
#include "spritebank.h"
#include "bitmapDrawing.h"
#include "bitTables.h"
#include "smallFont.h"
#include "tinyJoypadUtils.h"
#include "textUtils.h"

DUNGEON _dungeon;

/*--------------------------------------------------------*/
void setup()
{
#if defined(__AVR_ATtiny85__)
  SSD1306.ssd1306_init();
  // not using 'pinMode()' here saves ~100 bytes of flash!
  // configure A0, A3 and D1 as input
  DDRB &= ~( ( 1 << PB5) | ( 1 << PB3 ) | ( 1 << PB1 ) );
  // configure A2 as output
  DDRB |= ( 1 << PB4 );
#else
  // DEBUG version on controller with serial ports
  Serial.begin( 115200 );
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  // use 'pinMode()' for simplicity's sake... any other micro controller has enough flash :)
  pinMode( LEFT_RIGHT_BUTTON, INPUT );
  pinMode( UP_DOWN_BUTTON, INPUT );
  pinMode( FIRE_BUTTON, INPUT );
#endif
}

/*--------------------------------------------------------*/
void loop()
{
  // Prepare the dungeon
  _dungeon.playerX = 1;
  _dungeon.playerY = 2;
  _dungeon.dir  = NORTH;
  // prepare player stats
  _dungeon.playerHP = 30;
  _dungeon.playerDAM = 10;
  _dungeon.playerKeys = 2;  

  // Prepare first level
  LEVEL_HEADER *header = (LEVEL_HEADER *)Level_1;
  _dungeon.levelWidth = header->width;
  _dungeon.levelHeight = header->height;
  // copy the level data to RAM
  memcpy_P( _dungeon.currentLevel, Level_1 + sizeof( LEVEL_HEADER ), _dungeon.levelWidth * _dungeon.levelHeight );

  // clear text buffer
  clearTextBuffer();

  while( 1 )
  {
    // update the status pane
    updateStatusPane( &_dungeon );

    // display the dungeon
    Tiny_Flip( &_dungeon );

    // update player's position and orientation
    checkPlayerMovement( &_dungeon );
  }
}

/*--------------------------------------------------------*/
void Tiny_Flip( DUNGEON *dungeon)
{
  uint8_t statusPaneOffset = 0; 
  
  for ( uint8_t y = 0; y < 8; y++)
  {
#if defined(__AVR_ATtiny85__)
    // initialize image transfer to segment 'y'
    SSD1306.ssd1306_send_command(0xb0 + y);
  #ifdef _USE_SH1106_
    // SH1106 internally uses 132 pixels/line,
    // output is (always?) centered, so we need to start at position 2
    SSD1306.ssd1306_send_command(0x02);
    SSD1306.ssd1306_send_command(0x10);  
  #else
    // classic SSD1306 supports only 128 pixels/line, so we start at 0
    SSD1306.ssd1306_send_command(0x00);
    SSD1306.ssd1306_send_command(0x10);  
  #endif    
    SSD1306.ssd1306_send_data_start();
#else
  // allocate a buffer in RAM
  uint8_t *buffer = display.getBuffer() + y * 128;
#endif
    
    for ( uint8_t x = 0; x < 96; x++ )
    {
      uint8_t pixels = getWallPixels( dungeon, x, y );
    #ifdef _SHOW_GRID_OVERLAY
      if ( ( x & 0x01 ) && ( y < 7 ) ) { pixels |= 0x80; }
      //if ( ( x & 0x07 ) == 0x07 ) { pixels |= 0x55; }
    #endif      
      #if defined(__AVR_ATtiny85__)
        SSD1306.ssd1306_send_byte( pixels );
      #else
        *buffer++ = pixels;
      #endif
    } // for x

    // display the dashboard here
    for ( uint8_t x = 0; x < 32; x++)
    {
      uint8_t pixels;
      if ( y | dungeon->playerHasCompass )
      {
        pixels = pgm_read_byte( statusPane + statusPaneOffset ) | displayText( x, y );
      }
      else
      {
        pixels = 0;
      }
      #if defined(__AVR_ATtiny85__)
        SSD1306.ssd1306_send_byte( pixels );
      #else
        *buffer++ = pixels;
      #endif
      statusPaneOffset++;
    }
    
#if defined(__AVR_ATtiny85__)
    // this line appears to be optional, as it was never called during the intro screen...
    // but hey, we still have some bytes left ;)
    SSD1306.ssd1306_send_data_stop();
#endif
  } // for y

#if !defined(__AVR_ATtiny85__)
  display.display();
#endif
}

/*--------------------------------------------------------*/
void checkPlayerMovement( DUNGEON *dungeon )
{
  // get pointer to cell in front of player
  uint8_t *cell = getCell( dungeon, dungeon->playerX, dungeon->playerY, +1, 0, dungeon->dir );

  if ( isLeftPressed() ) 
  {
    // turn left
    dungeon->dir = ( dungeon->dir - 1 ) & 0x03;
    stepSound();
  }
  
  if ( isRightPressed() )
  {
    // turn right
    dungeon->dir = ( dungeon->dir + 1 ) & 0x03;
    stepSound();
  }

  if ( isUpPressed() )
  {
    if ( ( ( *cell ) & FLAG_SOLID ) != FLAG_SOLID )
    {
      stepSound();
      stepSound();
      
      switch( dungeon->dir )
      {
        case NORTH:
          dungeon->playerY--; break;
        case EAST:
          dungeon->playerX++; break;
        case SOUTH:
          dungeon->playerY++; break;
        case WEST:
          dungeon->playerX--; break;
      }
    }
    else
    {
      wallSound();
    }
  }
  
  if ( isDownPressed() )
  {
    if ( ( *( getCell( dungeon, dungeon->playerX, dungeon->playerY, -1, 0, dungeon->dir ) ) & FLAG_SOLID ) != FLAG_SOLID )
    {
      stepSound();
      stepSound();
  
      switch( dungeon->dir )
      {
        case NORTH:
          dungeon->playerY++; break;
        case EAST:
          dungeon->playerX--; break;
        case SOUTH:
          dungeon->playerY--; break;
        case WEST:
          dungeon->playerX++; break;
      }
    }
    else
    {
      wallSound();
    }
  }

  // ... and ACTION!
  if ( isFirePressed() )
  {
    uint8_t cellValue = *cell;

    #if !defined(__AVR_ATtiny85__)
      dungeon->serialPrint();
      Serial.print( F("dungeon = ") );Serial.print( uint16_t( dungeon ) );
      Serial.print( F(", cell = ") );Serial.println( uint16_t( cell ) );
      Serial.println();
      Serial.print(F("*cell = "));printHexToSerial( cellValue );Serial.println();
    #endif

    INTERACTION_INFO interactionInfo;
    for ( uint8_t n = 0; n < sizeof( interactionData ) / sizeof( INTERACTION_INFO ); n++ )
    {
      // get data from progmem
      memcpy_P( &interactionInfo, interactionData + n, sizeof( INTERACTION_INFO ) );

      // does this info cover the current position?
      if (    ( cell == dungeon->currentLevel + interactionInfo.currentPosition )
           //|| ( interactionInfo.currentPosition == ANY_POSITION )
         )
      {
        // is the status correct?
        if ( ( cellValue & interactionInfo.currentStatusMask ) == interactionInfo.currentStatus )
        {
        #if !defined(__AVR_ATtiny85__)
          Serial.print(F("+ Matching entry found <"));Serial.print( n );Serial.println(F(">"));
          // print entry information
          interactionInfo.serialPrint();
        #endif

          // special handling for special types
          if ( cellValue == CLOSED_CHEST )
          {
            // plunder the chest!
            openChest( dungeon, interactionInfo );
          }

          // yay!
          *cell = ( cellValue - interactionInfo.currentStatus ) | interactionInfo.nextStatus;
          // check target position
          //if ( interactionInfo.modifiedPosition == ANY_POSITION )
          //{
          //  // modify current position
          //  *cell = interactionInfo.modifiedPositionCellValue;
          //}
          //else
          {
            // modify target position
            dungeon->currentLevel[interactionInfo.modifiedPosition] = interactionInfo.modifiedPositionCellValue;
          }
          swordSound();
          
          // perform only the first action, otherwise on/off actions might be immediately revoked ;)
          break;
        }
      }
    }
  }
  
  // limit the positions
  limitDungeonPosition( dungeon, dungeon->playerX, dungeon->playerY );
}

/*--------------------------------------------------------*/
void stepSound()
{
  Sound( 100,1 );
  Sound( 200,1 );
  _delay_ms( 100 );
}

/*--------------------------------------------------------*/
void wallSound()
{
  Sound( 50,1 );
  _delay_ms( 100 );
}

/*--------------------------------------------------------*/
void swordSound()
{
  Sound( 50,10 );
}
