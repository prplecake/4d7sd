#include <Arduino.h>
#include "../lib/SevSeg/SevSeg.h"

// Initialize a seven segment controller object
SevSeg sevseg;


__attribute__((unused)) void setup( )
{
    byte numDigits = 4;
    byte digitPins[] = { 2, 3, 4, 5 };
    byte segmentPins[] = { 6, 7, 8, 9, 10, 11, 12, 13 };
    bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
    sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
}

/*
 * Main program loop.
 */
__attribute__((unused)) void loop( )
{
    sevseg.setChars("Halo");
    sevseg.refreshDisplay();
}
