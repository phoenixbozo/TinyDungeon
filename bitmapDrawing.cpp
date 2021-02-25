#include <Arduino.h>
#include "dungeon.h"
#include "dungeonTypes.h"
#include "spritebank.h"
#include "bitmapDrawing.h"
#include "bitTables.h"

/*--------------------------------------------------------*/
uint8_t getWallPixels( DUNGEON *dungeon, const int8_t x, const int8_t y )
{
  uint8_t pixels = 0;

  SIMPLE_WALL_INFO wallInfo;
  
  const SIMPLE_WALL_INFO *wallInfoPtr = arrayOfWallInfo;

  // all objects are visible
  int8_t maxObjectDistance = 4;

  // iterate through the whole list (at least as long as it's necessary)
  while( true )
  {
    // the structure resides in PROGMEM, so we need to copy it to RAM first...
    memcpy_P( &wallInfo, wallInfoPtr, sizeof( wallInfo ) );

    // end of list reached?
    if ( wallInfo.wallBitmap == NULL ) { break; }

    // check conditions
    if ( ( x >= wallInfo.startPosX ) && ( x <= wallInfo.endPosX ) )
    {
      // is there a wall object?
      if ( ( *( getCell( dungeon, dungeon->playerX, dungeon->playerY, wallInfo.viewDistance, wallInfo.leftRightOffset, dungeon->dir ) ) & WALL_MASK ) == wallInfo.objectMask )
      {
        // mirror walls on odd fields
        uint8_t offsetX = ( ( dungeon->playerX + dungeon->playerY ) & 0x01 ) ? 95 - x : x;
        // get wall pixels
        pixels = pgm_read_byte( wallInfo.wallBitmap + y * 96 + offsetX );
        // objects behind walls not invisible, but doors or switched might be placed *on* walls
        maxObjectDistance = wallInfo.viewDistance;
        // that's it!
        break;
      }
    }
    // move to next entry
    wallInfoPtr++;
  }

  NON_WALL_OBJECT object;

  // draw NWOs (Non Wall Objects) over the wall pixls (with mask!)
  for ( uint8_t distance = maxObjectDistance; distance > 0; distance-- )
  {
    for ( uint8_t n = 0; n < sizeof( objectList ) / sizeof( objectList[0] ); n++ )
    {
      memcpy_P( &object, &objectList[n], sizeof( object ) );
      uint8_t objectWidth = object.bitmapWidth >> distance;

      if ( ( x >= WINDOW_CENTER_X - objectWidth ) && ( x < WINDOW_CENTER_X + objectWidth ) )
      {
        if ( ( *( getCell( dungeon, dungeon->playerX, dungeon->playerY, distance, 0, dungeon->dir ) ) & OBJECT_MASK ) == object.itemType )
        {
          objectWidth = WINDOW_CENTER_X - objectWidth;
          uint8_t posX = x - objectWidth;
          uint8_t scalingFactor = pgm_read_byte( scalingFactorFromDistance + distance );
          // free background
          pixels &= getDownScaledBitmapData( posX, y, distance, &object, true );
          // and overlay scaled bitmap
          pixels |= getDownScaledBitmapData( posX, y, distance, &object, false );
        }
      }
    }
  }
  
  return( pixels );
}

/*--------------------------------------------------------*/
// Returns the downscaled bitmap data at position x,y.
// Supported distance values are 1, 2, 3.
// Note that x is scaled by the scale factor for
// the current distance, while y remains unscaled!
uint8_t getDownScaledBitmapData( int8_t x,                      // already downscaled by 1 << ( distance - 1 )
                                 int8_t y,                      // unscaled vertical position
                                 const uint8_t distance,        // supported values are 1..3
                                 const NON_WALL_OBJECT *object, // current non wall object
                                 bool useMask                   // if true returns the down scaled mask
                               )
{
  uint8_t pixels = 0;

  // get start address (and add optional offset for mask)
  uint8_t *bitmapData = object->bitmapData;
  if ( useMask ) { bitmapData += object->maskOffset; }

  // get scaling factor from LUT (efficient and still flexible)
  uint8_t scaleFactor = pgm_read_byte( scalingFactorFromDistance + distance );
  // get threshold
  const uint8_t threshold = object->scalingThreshold[distance];

  // is there anything to be done?
  uint8_t startOffsetY = pgm_read_byte( verticalStartOffset + distance );
  uint8_t endOffsetY = pgm_read_byte( verticalEndOffset + distance );

  if ( ( y >= startOffsetY ) && ( y <= endOffsetY ) )
  {
    //Serial.print(F("x = "));Serial.print( x );Serial.print(F(", y = "));Serial.print( y );
    //Serial.print(F(", distance = "));Serial.print( distance );
    //Serial.print(F(", scaleFactor = "));Serial.print( scaleFactor );
    //Serial.print(F(", threshold = "));Serial.print( threshold );
    //Serial.print(F(", startOffsetY = "));Serial.print( startOffsetY );
    //Serial.print(F(", endOffsetY = "));Serial.print( endOffsetY );
    //Serial.println();
  
    // modify positions in source bitmap by scaling factor
    x = x * scaleFactor;
    // correct y position by start offset
    y -= startOffsetY;
    
    // get appropriate bit mask
    uint8_t bitMask = pgm_read_byte( bitMaskFromScalingFactor + scaleFactor );
  
    // calculate start address
    const uint8_t *data = bitmapData + y * scaleFactor * object->nextLineOffset + x;
  
    // first bit to be processed
    uint8_t bitNo = 0;
    uint8_t byteNo = 0;
  
    // We need to calculate 8 vertical output bits...
    // NOTE: Because the Tiny85 only supports shifting by 1 bit, it is
    //       more efficient to do the shifting in the 'for' loop instead
    //       of using a ( 1 << n ) construct.
    for ( uint8_t bitValue = 1; bitValue != 0; bitValue <<= 1 )
    {
      uint8_t bitSum = 0;
  
      if ( byteNo >= object->bitmapVerticalOffsetInBytes )
      {
        // go over the columns - all required bits always are in one row
        for ( uint8_t col = 0; col < scaleFactor; col++ )
        {
          // to get the output value, we will sum all the bits up (using a lookup table saves time and flash space)
          bitSum += pgm_read_byte( nibbleBitCount + ( ( pgm_read_byte( data++ ) >> bitNo ) & bitMask ) );
        }
        // correct the post increments from before
        data -= scaleFactor;
      }
  
      // next bit position
      bitNo += scaleFactor;
  
      if ( bitNo >= 8 )
      {
        // a new byte will begin...
        byteNo++;
        // with bit 0
        bitNo = 0;
        // did we already use some image data?
        if ( byteNo > object->bitmapVerticalOffsetInBytes )
        {
          // address next 8-pixel row
          data += object->nextLineOffset;
        }
      }
  
      // calculate output pixel
      if ( bitSum >= threshold )
      {
        pixels |= bitValue;
      }
    }
  }
  // no bits here, set mask to 0xff
  else if ( useMask )
  { 
    pixels--;
  }
                                     
  return( pixels );  
}
