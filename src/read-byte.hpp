#pragma once
#include <Arduino.h>

uint8_t readByte(int pin, int delayTime)
{
    // Record the start time once at the beginning
    unsigned long startTime = micros();

    uint8_t out = 0;

    // Read each bit, starting with the MSB
    for (uint8_t i = 0; i < 8; i++)
    {
        // Read the pin and set the corresponding bit
        out |= (digitalRead(pin) == HIGH) << i;

        // Calculate the target time for this bit
        unsigned long targetTime = startTime + (i * delayTime);

        // Wait until it's time to read the current bit
        while (micros() < targetTime)
        {
        }
    }

    return out;
}