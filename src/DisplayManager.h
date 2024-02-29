#ifndef DisplayManager_h
#define DisplayManager_h

#include "GameState.h"
#include <Adafruit_NeoPixel.h>
#include <U8g2lib.h>

class DisplayManager {
public:
    DisplayManager(GameState& gameState, Adafruit_NeoPixel& pixels1, Adafruit_NeoPixel& pixels2, U8G2& oledDisplay);
    void updateDisplay();

private:
    GameState& gameState;
    Adafruit_NeoPixel& pixels1;
    Adafruit_NeoPixel& pixels2;
    U8G2& oledDisplay;
};

#endif