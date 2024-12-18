#include <Arduino.h>
#include "./user.hpp"
#include "./send-byte.hpp"
#include "./read-byte.hpp"
#include "./wait-for-header.hpp"

#define DATA_PIN 25
#define DEFAULT_SEND_FREQUENCY 700 // Increased delay for better timing

void setup()
{
    Serial.begin(115200);
    Serial.println(IS_SENDING ? "SENDER" : "RECIEVER");

    pinMode(DATA_PIN, IS_SENDING ? OUTPUT : INPUT);
    if (IS_SENDING)
        digitalWrite(DATA_PIN, LOW); // Set initial state
}

void loop()
{
#if IS_SENDING
    sendByte(0b11110000, DATA_PIN, DEFAULT_SEND_FREQUENCY);
    sendByte(0b11110000, DATA_PIN, DEFAULT_SEND_FREQUENCY);
    sendByte(123, DATA_PIN, DEFAULT_SEND_FREQUENCY);
    Serial.println("SENDED: 123");
#else
    waitForHeader(0b1111000011110000, DATA_PIN, DEFAULT_SEND_FREQUENCY);
    uint8_t received = readByte(DATA_PIN, DEFAULT_SEND_FREQUENCY);
    Serial.println(String("RECIVED: ") + String(received)); // Proper string concatenation
#endif
}