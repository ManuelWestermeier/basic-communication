#pragma once

#include <Arduino.h>

// Reads 8 bits from the specified pin and returns them as a byte
uint8_t readByte(int pin, int delayTime)
{
    uint8_t out = 0;

    for (uint8_t i = 0; i < 8; i++)
    {
        // Shift left and set the current bit if pin reads HIGH
        out |= (digitalRead(pin) == HIGH) << i;

        // Delay for the specified time
        delay(delayTime);
    }

    return out;
}