// NeoPixelManager.cpp
#include "NeoPixelManager.h"

// Constructor
NeoPixelManager::NeoPixelManager(uint8_t pin, uint16_t numPixels) : pixels(numPixels, pin, NEO_GRB + NEO_KHZ800) {}

// Method to initialize the NeoPixel strip
void NeoPixelManager::begin() {
    pixels.begin();
    pixels.show(); // Initialize all pixels to 'off'
}

// Method to display the energy level
void NeoPixelManager::displayEnergyLevel(int energyLevel) {
    int numLitPixels = map(energyLevel, 0, 16, 0, pixels.numPixels());
    
    for (int i = 0; i < pixels.numPixels(); i++) {
        if (i < numLitPixels) {
            pixels.setPixelColor(i, pixels.Color(0, 150, 0)); // Green for "charged" pixels
        } else {
            // Optionally, create a fading effect here
            int fadeValue = max(0, 150 - ((i - numLitPixels) * (150 / pixels.numPixels())));
            pixels.setPixelColor(i, pixels.Color(0, fadeValue, 0)); // Fade for "uncharged" pixels
        }
    }
    
    pixels.show();
}
