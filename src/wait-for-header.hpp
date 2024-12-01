#pragma once
#include <Arduino.h>

// Waits for a specific 16-bit header sequence on the specified pin
void waitForHeader(uint16_t header, int pin, int delayTime)
{
    // Record the start time once at the beginning
    unsigned long startTime = micros();

    uint16_t headerReceived = 0;

    uint16_t receivedIndex = 0;
    // Pre-fill headerReceived by reading the first 15 bits
    for (; receivedIndex < 15; receivedIndex++)
    {
        // Shift left and read the next bit
        headerReceived = (headerReceived << 1) | (digitalRead(pin) == HIGH);

        // Calculate the target time for this bit
        unsigned long targetTime = startTime + (receivedIndex * delayTime);

        // Wait until it's time to read the current bit
        while (micros() < targetTime)
        {
        }
    }

    // Continuously read bits until the header is matched
    while (true)
    {
        receivedIndex++;
        // Shift left and add the next bit
        headerReceived = (headerReceived << 1) | (digitalRead(pin) == HIGH);

        // Calculate the target time for this bit
        unsigned long targetTime = startTime + (receivedIndex * delayTime);

        // Wait until it's time to read the current bit
        while (micros() < targetTime)
        {
        }

        // Check if the header matches
        if (headerReceived == header)
        {
            return; // Header detected
        }
    }
}
