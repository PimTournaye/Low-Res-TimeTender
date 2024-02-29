#ifndef ClockMechanism_h
#define ClockMechanism_h

#include "GameState.h"
#include <ESP32Encoder.h>

class ClockMechanism {
public:
    ClockMechanism(GameState& gameState);
    void setup();
    void update();

private:
    GameState& gameState;
    ESP32Encoder encoder;
    long lastPosition;
};

#endif
