#include "NeoPixelManager.h"

NeoPixelManager::NeoPixelManager(Adafruit_NeoPixel& pixels) : pixels(pixels) {
    this->pixels.begin();
}

void NeoPixelManager::displayEnergyLevel(int level) {
    pixels.clear();
    for (int i = 0; i < level; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    }
    pixels.show();
}

void NeoPixelManager::displayAnimation() {
    // Implementation of your animation
}
