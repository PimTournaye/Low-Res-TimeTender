#ifndef NeoPixelManager_h
#define NeoPixelManager_h

#include <Adafruit_NeoPixel.h>

class NeoPixelManager {
public:
    NeoPixelManager(Adafruit_NeoPixel& pixels);
    void displayEnergyLevel(int level);
    void displayAnimation(); // Placeholder for animation method
private:
    Adafruit_NeoPixel& pixels;
};

#endif
