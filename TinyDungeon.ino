//   >>>>>  T-I-N-Y  D-U-N-G-E-O-N v0.1 for ATTINY85  GPLv3 <<<<
//						Tinyjoypad rev2 compatible
//                   Programmer: Sven B 2020
//              Contact EMAIL: 

//the code works at 16MHZ internal
//and use ssd1306xled Library for SSD1306 oled display 128x64

#include <ssd1306xled.h>
#include "Dungeon.h"
#include "RLEdecompression.h"
#include "smallFont.h"
#include "TinyJoystickControls.h"

int8_t playerX = 6;
int8_t playerY = 3;
uint8_t dir  = NORTH;

uint8_t level_height = 8;
uint8_t level_width = 8;
const uint8_t *level = Level_1;

#define LEVEL_SIZE_X  8
#define LEVEL_SIZE_Y  8

/*--------------------------------------------------------*/
void setup()
{
  SSD1306.ssd1306_init();
  // not using 'pinMode()' here saves ~100 bytes of flash!
  // configure A0, A3 and D1 as input
  DDRB &= ~( ( 1 << PB5) | ( 1 << PB3 ) | ( 1 << PB1 ) );
  // configure A2 as output
  DDRB |= ( 1 << PB4 );
}

/*--------------------------------------------------------*/
void loop()
{
  Tiny_Flip();

  // update player's position and orientation
  checkPlayerMovement();
 
  _delay_ms( 200 );
}

/*--------------------------------------------------------*/
void Tiny_Flip()
{
  for ( uint8_t y = 0; y < 8; y++)
  {
    // initialize image transfer to segment 'y'
    SSD1306.ssd1306_send_command(0xb0 + y);
    SSD1306.ssd1306_send_command(0x00); 
    SSD1306.ssd1306_send_command(0x10);  
    SSD1306.ssd1306_send_data_start();
    
    for ( uint8_t x = 0; x < 96; x++ )
    {
      uint8_t pixels = getWallPixels( x, y );
      SSD1306.ssd1306_send_byte( pixels );
    } // for x

    // display the dashboard here (later)
    for ( uint8_t x = 96; x < 128; x++)
    {
      SSD1306.ssd1306_send_byte( 0 );
    }
    
    // this line appears to be optional, as it was never called during the intro screen...
    // but hey, we still have some bytes left ;)
    SSD1306.ssd1306_send_data_stop();
  } // for y
}

/*--------------------------------------------------------*/
uint8_t getWallPixels( const int8_t x, const int8_t y )
{
  uint8_t pixel = 0;
  
  // check for a wall right in front
  if ( ( pgm_read_byte( getCell( playerX, playerY, 1, 0, dir ) ) & WALL_MASK ) == WALL )
  {
    pixel = pgm_read_byte( frontWalls_D1 + y * 96 + x );
  }
  // now it's getting trickier:
  // - we need to check if a wall is to the left or right, too!
  else if (    ( ( x <= 24 ) && ( ( pgm_read_byte( getCell( playerX, playerY, 1, -1, dir ) ) & WALL_MASK ) == WALL ) )
            || ( ( x >= 71 ) && ( ( pgm_read_byte( getCell( playerX, playerY, 1, +1, dir ) ) & WALL_MASK ) == WALL ) )
          )
  {
    pixel = pgm_read_byte( leftRightWalls + y * 96 + x );
  }
  
  // check for a wall in front in distance 2
  else if (    ( ( x > 24 ) && ( x < 71 ) &&( pgm_read_byte( getCell( playerX, playerY, 2, 0, dir ) ) & WALL_MASK ) == WALL )
            || ( ( x <= 24 ) && ( pgm_read_byte( getCell( playerX, playerY, 2, -1, dir ) ) & WALL_MASK ) == WALL )
            || ( ( x >= 71 ) && ( pgm_read_byte( getCell( playerX, playerY, 2, +1, dir ) ) & WALL_MASK ) == WALL )
          )
  {
    pixel = pgm_read_byte( frontWalls_D2 + y * 96 + x );
  }
  // check for walls to the left and right in 2 steps distance
  else if (    ( ( x > 24 ) && ( x <= 37 ) && ( ( pgm_read_byte( getCell( playerX, playerY, 2, -1, dir ) ) & WALL_MASK ) == WALL ) )
            || ( ( x >= 58 ) && ( x < 71 ) && ( ( pgm_read_byte( getCell( playerX, playerY, 2, +1, dir ) ) & WALL_MASK ) == WALL ) )
          )
  {
    pixel = pgm_read_byte( leftRightWalls + y * 96 + x );
  }
  
  // check for a wall in front in distance 3
  else if (    ( ( x <= 11 )                && ( pgm_read_byte( getCell( playerX, playerY, 3, -2, dir ) ) & WALL_MASK ) == WALL )
            || ( ( x >  11 ) && ( x <= 35 ) && ( pgm_read_byte( getCell( playerX, playerY, 3, -1, dir ) ) & WALL_MASK ) == WALL )
            || ( ( x >  35 ) && ( x <= 59 ) && ( pgm_read_byte( getCell( playerX, playerY, 3,  0, dir ) ) & WALL_MASK ) == WALL )
            || ( ( x >  59 ) && ( x <  84 ) && ( pgm_read_byte( getCell( playerX, playerY, 3, +1, dir ) ) & WALL_MASK ) == WALL )
            || ( ( x >= 84 )                && ( pgm_read_byte( getCell( playerX, playerY, 3, +2, dir ) ) & WALL_MASK ) == WALL )
          )
  {
    pixel = pgm_read_byte( frontWalls_D3 + y * 96 + x );
  }

  return( pixel );
}

/*--------------------------------------------------------*/
// Returns a pointer to the cell which is 
// - 'distance' away 
// - in direction 'orientation'
// - from position 'x', 'y'
// This function supports a wrap-around, so endless corridors are possible :)
uint8_t *getCell( int8_t x, int8_t y, const int8_t distance, const int8_t offsetLR, const uint8_t orientation )
{
  switch( orientation )
  {
    case NORTH:
    {
      y -= distance;
      x += offsetLR;
      break;
    }
    case SOUTH:
    {
      y += distance;
      x -= offsetLR;
      break;
    }
    case EAST:
    {
      x += distance;
      y += offsetLR;
      break;
    }
    case WEST:
    {
      x -= distance;
      y -= offsetLR;
      break;
    }
  }

  limitDungeonPosition( x, y );

  return( level + y * level_width + x );
}

/*--------------------------------------------------------*/
void checkPlayerMovement()
{
  if ( isLeftPressed() ) 
  {
    // turn left
    dir = ( dir - 1 ) & 0x03;
  }
  if ( isRightPressed() )
  {
    // turn right
    dir = ( dir + 1 ) & 0x03;
  }
  if ( isUpPressed() )
  {
    Sound(100,1);
    Sound(200,1);
    
    switch( dir )
    {
      case NORTH:
        playerY--;
        break;
      case EAST:
        playerX++;
        break;
      case SOUTH:
        playerY++;
        break;
      case WEST:
        playerX--;
        break;
    }
  }
  if ( isDownPressed() )
  {
    Sound(100,1);
    Sound(200,1);

    switch( dir )
    {
      case NORTH:
        playerY++;
        break;
      case EAST:
        playerX--;
        break;
      case SOUTH:
        playerY--;
        break;
      case WEST:
        playerX++;
        break;
    }
  }
  
  // limit the positions
  limitDungeonPosition( playerX, playerY );
}

/*--------------------------------------------------------*/
// Limits the position in the dungeon, but enables wrap-around :)
void limitDungeonPosition( int8_t &x, int8_t &y )
{
  if ( x < 0 ) { x += level_width; }
  if ( x >= level_width ) { x -= level_width; }
  if ( y < 0 ) { y += level_height; }
  if ( y >= level_height ) { y -= level_height; }
}
