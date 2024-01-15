#include <Arduino.h>

// Initialize pins
#define LATCH 9
#define CLOCK 10
#define DATA 8

__attribute__((unused)) void setup( )
{
    pinMode(LATCH, OUTPUT);
    pinMode(CLOCK, OUTPUT);
    pinMode(DATA, OUTPUT);
}


unsigned char table[] = {
        /* 0000 0000 where bit represents segment dp-g-f-e d-c-b-a */
        0x3f,  // 0: 00111111
        0x06,  // 1: 00000110
        0x5b,  // 2: 01011011
        0x4f,  // 3: 01001111
        0x66,  // 4: 01100110
        0x6d,  // 5: 01101101
        0x7d,  // 6: 01111101
        0x07,
        0x7f,
        0x6f,
        0x77,
        0x7c,
        0x39,
        0x5e,
        0x79,
        0x71
};

void display(unsigned char num)
{
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, table[num]);
    digitalWrite(LATCH, HIGH);
}

/*
 * Main program loop.
 */
__attribute__((unused)) void loop( )
{
    // Display numbers 0 through 16 with a delay of 500 ms between each
    for (unsigned int i = 0; i < 16; i++ ){
        display(i);
        delay(500);
    }
}
