#pragma once

#include <Arduino.h>

// Waits for a specific 16-bit header sequence on the specified pin
void waitForHeader(uint16_t header, int pin, int delayTime)
{
    uint16_t headerReceived = 0;

    // Pre-fill headerReceived by reading the first 15 bits
    for (int receivedIndex = 0; receivedIndex < 15; receivedIndex++)
    {
        // Shift left and read the next bit
        headerReceived = (headerReceived << 1) | (digitalRead(pin) == HIGH);

        // Wait for the specified time
        delay(delayTime);
    }

    // Continuously read bits until the header is matched
    while (true)
    {
        // Shift left and add the next bit
        headerReceived = (headerReceived << 1) | (digitalRead(pin) == HIGH);

        // Check if the header matches
        if (headerReceived == header)
        {
            return; // Header detected
        }

        // Wait for the specified time
        delay(delayTime);
    }
}