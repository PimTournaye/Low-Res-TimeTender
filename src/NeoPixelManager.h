#ifndef NeoPixelManager_h
#define NeoPixelManager_h

#include <Adafruit_NeoPixel.h>

class NeoPixelManager {
public:
    NeoPixelManager(uint8_t pin, uint16_t numPixels);
    void displayEnergyLevel(int energyLevel);
    void begin();  // Add a begin function to initialize the pixels

private:
    Adafruit_NeoPixel pixels;
};

#endif