#include <Arduino.h>
#include "RotaryEncoder.h"
#include "NeoPixelManager.h"

// Which pin on the Arduino is connected to the NeoPixels?
#define PIXEL_1_PIN        19
#define PIXEL_2_PIN        16
#define NUMPIXELS 16 

// Buttons
#define BUTTON_1_PIN         21
#define BUTTON_2_PIN         5

// Rotary Encoder
#define ROTARY_ENCODER_PIN_A  13
#define ROTARY_ENCODER_PIN_B  12
#define ROTARY_ENCODER_PIN_SW  17


Adafruit_NeoPixel pixels1(NUMPIXELS, PIXEL_1_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS, PIXEL_2_PIN, NEO_GRB + NEO_KHZ800);
RotaryEncoder encoder(12, 13); // Initialize with your encoder pins
NeoPixelManager neoPixelManager1(pixels1);
NeoPixelManager neoPixelManager2(pixels2);


void setup() {
    Serial.begin(115200);
}

void loop() {
    encoder.update(); // Check for rotation and update accordingly
    int energyLevel = encoder.getPosition(); // Example: use encoder position as energy level
    int mappedLevel = map(energyLevel, 0, 300, 0, NUMPIXELS);
    neoPixelManager1.displayEnergyLevel(abs(mappedLevel)); // Update NeoPixels based on energy level
    neoPixelManager2.displayEnergyLevel(abs(mappedLevel / 2)); // Update NeoPixels based on energy level
}