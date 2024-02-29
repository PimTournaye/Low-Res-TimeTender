#ifndef RotaryEncoder_h
#define RotaryEncoder_h

#include <ESP32Encoder.h>
#include <Arduino.h>

class RotaryEncoder {
public:
    RotaryEncoder(uint8_t pinA, uint8_t pinB);
    long getPosition();
    void update();
private:
    ESP32Encoder encoder;
    long lastPosition;
};

#endif