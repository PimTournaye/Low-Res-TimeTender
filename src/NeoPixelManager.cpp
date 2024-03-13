/**
 * @file NeoPixelManager.cpp
 * @brief Implementation file for the NeoPixelManager class.
 */

#include "NeoPixelManager.h"

/**
 * @brief Constructor for the NeoPixelManager class.
 * @param pixels Reference to an Adafruit_NeoPixel instance.
 * @param timeManager Pointer to a TimeManager instance.
 */
NeoPixelManager::NeoPixelManager(Adafruit_NeoPixel &pixels, TimeManager* timeManager)
: pixels(pixels), timeManager(timeManager) {
    // Constructor body can be empty if there's nothing else to initialize
}

/**
 * @brief Fades out the LEDs from their current state to 0 brightness.
 */
void NeoPixelManager::fadeOutLEDs() {
    // Fade out the LEDs from their current state to 0 using setBrightness
    for (int i = 255; i > 0; i--) {
        pixels.setBrightness(i);
        pixels.show();
        delay(10);
    }
    pixels.clear();
}

// Winds up LEDs depending on how after we've been turning the rotary encoder
void NeoPixelManager::windupLEDs(int rotationSpeed) {
    // Map speed to the number of LEDs to light up
    int MAX_SPEED = 100; 
    int numLEDsLit = map(rotationSpeed, 0, MAX_SPEED, 0, numPixels);

    for (int i = 0; i < numPixels; i++) {
        if (i < numLEDsLit) {
            pixels.setPixelColor(i, pixels.Color(0, 150, 0)); // Green for "active" LEDs
        } else {
            pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Turn off the rest
        }
    }
    pixels.show();
}


/**
 * @brief Displays the energy level on the NeoPixel strip.
 * @param mappedEnergyLevel The mapped energy level value.
 */
void NeoPixelManager::displayEnergyLevel(int mappedEnergyLevel) {
    // Clear any previous Tasker timeouts
    // tasker.cancel(this->fadeOutLEDs);
    int fullPixels = (mappedEnergyLevel * numPixels) / 100; // Calculate fully lit pixels
    int partialPixelBrightness = ((mappedEnergyLevel * 255) / 100) % (255 / numPixels); // Brightness of partially lit pixel

    for (int i = 0; i < numPixels; i++) {
        if (i < fullPixels) {
            // Full brightness for fully lit pixels
            pixels.setPixelColor(i, pixels.Color(0, 150, 0)); // Green for "charged" pixels
        } else if (i == fullPixels) {
            // Partial brightness for the next pixel
            pixels.setPixelColor(i, pixels.Color(0, partialPixelBrightness, 0));
        } else {
            // Turn off the rest of the pixels
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
        }
    }
    pixels.show();
    // Set a new timeout for fading out LEDs
    // tasker.setTimeout(NeoPixelManager::fadeOutLEDs, 1000);
}


/**
 * @brief Displays the underclocked state on the NeoPixel strip.
 * @param mappedEnergyLevel The mapped energy level value.
 */
void NeoPixelManager::displayUnderclocked(int mappedEnergyLevel) {
    // TODO: Implement the displayUnderclocked method
}

/**
 * @brief Displays the overclocked state on the NeoPixel strip.
 * @param mappedEnergyLevel The mapped energy level value.
 */
void NeoPixelManager::displayOverclocked(int mappedEnergyLevel) {
    // TODO: Implement the displayOverclocked method
}

/**
 * @brief Pulses the clock on the NeoPixel strip.
 * @param mappedEnergyLevel The mapped energy level value.
 */
void NeoPixelManager::pulseClock(int mappedEnergyLevel) {
    // TODO: Implement the pulseClock method
}






// /**
//  * @brief Displays the energy level on the NeoPixel strip.
//  * @param mappedEnergyLevel The mapped energy level value.
//  */
// void NeoPixelManager::displayEnergyLevel(int mappedEnergyLevel) {
//     int fullPixels = (mappedEnergyLevel * numPixels) / 100; // Calculate fully lit pixels
//     int partialPixelBrightness = ((mappedEnergyLevel * 255) / 100) % (255 / numPixels); // Brightness of partially lit pixel

//     for (int i = 0; i < numPixels; i++) {
//         if (i < fullPixels) {
//             // Full brightness for fully lit pixels
//             pixels.setPixelColor(i, pixels.Color(0, 150, 0)); // Green for "charged" pixels
//         } else if (i == fullPixels && fullPixels > 0) {
//             // Partial brightness for the next pixel
//             pixels.setPixelColor(i, pixels.Color(0, partialPixelBrightness, 0));
//         } else {
//             // Turn off the rest of the pixels
//             pixels.setPixelColor(i, pixels.Color(0, 0, 0));
//         }
//     }
//     pixels.show();
// }