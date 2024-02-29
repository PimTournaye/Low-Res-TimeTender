#include <Arduino.h>
#include <ESP32Encoder.h>
#include <Adafruit_NeoPixel.h>


// Which pin on the Arduino is connected to the NeoPixels?
#define PIXEL_1_PIN        19
#define PIXEL_2_PIN        nullptr

#define BUTTON_1_PIN         21
#define BUTTON_2_PIN         5

// Rotary Encoder
#define ROTARY_ENCODER_PIN_A  12
#define ROTARY_ENCODER_PIN_B  13
#define ROTARY_ENCODER_PIN_SW  17

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 16 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIXEL_1_PIN, NEO_GRB + NEO_KHZ800);
ESP32Encoder encoder;

#define DELAYVAL 50 // Time (in milliseconds) to pause between pixels

void setup() {
  pixels.begin(); 
  encoder.attachHalfQuad ( ROTARY_ENCODER_PIN_A, ROTARY_ENCODER_PIN_B );
  encoder.setCount ( 0 );
  Serial.begin ( 115200 );
}

  unsigned long previousMillis = 0;
  const unsigned long interval = 50; // Time (in milliseconds) to pause between pixels


void loop() {
  
  long newPosition = encoder.getCount() / 2;
  Serial.println(newPosition);
  pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.

  for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    pixels.show(); // Send the updated pixel colors to the hardware.

    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      // Continue with the next iteration of the loop
    }
  }
}