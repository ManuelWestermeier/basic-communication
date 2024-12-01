#pragma once

#include <Arduino.h>

// Sends a byte one bit at a time over a digital pin
void sendByte(uint8_t value, int pin, int delayTime)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        // Extract the bit at position `i`
        bool bit = (value & (1 << i)) != 0;

        // Write HIGH or LOW to the pin
        digitalWrite(pin, bit ? HIGH : LOW);

        // Delay for the specified time
        delay(delayTime);
    }
}