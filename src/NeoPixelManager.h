#ifndef NeoPixelManager_h
#define NeoPixelManager_h

#include "TimeManager.h"
#include <Adafruit_NeoPixel.h>

class NeoPixelManager {
public:
    NeoPixelManager(Adafruit_NeoPixel &pixels, TimeManager* timeManager);
    // Display the energy level mapped over the pixels
    void displayEnergyLevel(int mappedEnergyLevel);
    void displayUnderclocked(int mappedEnergyLevel);
    void displayOverclocked(int mappedEnergyLevel);
    void pulseClock(int mappedEnergyLevel);
    void fadeOutLEDs();
    void windupLEDs(int rotationSpeed);

private:
    Adafruit_NeoPixel &pixels; // Reference to an Adafruit_NeoPixel instance
    TimeManager* timeManager; // Pointer to a TimeManager instance
    uint16_t numPixels = 16; // Number of pixels in the strip
};

#endif