#include "RotaryEncoder.h"

RotaryEncoder::RotaryEncoder(uint8_t pinA, uint8_t pinB) {
    encoder.attachHalfQuad(pinA, pinB);
    encoder.setCount(0);
    lastPosition = 0;
}

long RotaryEncoder::getPosition() {
    return encoder.getCount() / 2; // Adjust as needed for your encoder
}

void RotaryEncoder::update() {
    long newPosition = getPosition();
    if (newPosition != lastPosition) {
        lastPosition = newPosition;
        Serial.println(newPosition);
        // Additional code for handling rotation can go here
    }
}
