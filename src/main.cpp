#include <Arduino.h>
// #include <SPI.h>
// #include <Wire.h>
#include <WiFi.h>
#include <HTTPClient.h>

#include <Tasker.h>
#include <Adafruit_NeoPixel.h>

#include "RotaryEncoder.h"
#include "NeoPixelManager.h"
#include "TimeManager.h"
#include "WiFiManager.h"

// Which pin on the Arduino is connected to the NeoPixels?
#define PIXEL_1_PIN 19
#define PIXEL_2_PIN 16
#define NUMPIXELS 16

// Buttons
#define BUTTON_1_PIN 21
#define BUTTON_2_PIN 5

// Rotary Encoder
#define ROTARY_ENCODER_PIN_A 13
#define ROTARY_ENCODER_PIN_B 12
#define ROTARY_ENCODER_PIN_SW 17

// OLED
// #define OLED_SDA 23
// #define OLED_SCL 22
// #define SCREEN_WIDTH 128 // OLED display width, in pixels
// #define SCREEN_HEIGHT 64 // OLED display height, in pixels
// #define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
// #define SCREEN_ADDRESS 0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

// WiFi
const char *ssid = "SSID";
const char *password = "password1234";
const char *serverName = "http://192.168.178.44:5173/state";

// Create an instance of the classes
TimeManager timeManager;
WiFiManager wifiManager(ssid, password, serverName);
Tasker tasker;
RotaryEncoder encoder(ROTARY_ENCODER_PIN_A, ROTARY_ENCODER_PIN_B, timeManager);

Adafruit_NeoPixel energyPixels(NUMPIXELS, PIXEL_1_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel windupPixels(NUMPIXELS, PIXEL_2_PIN, NEO_GRB + NEO_KHZ800);
NeoPixelManager energyPixelsManager(energyPixels, &timeManager);
NeoPixelManager windupManager(windupPixels, &timeManager);

const long updateInterval = 10000; // 10 sec
unsigned long lastUpdate = 0;
bool sendingPassedTime = false;
int builtInLEDState = LOW;

uint16_t mapEnergyLevel() {
  return map(timeManager.getEnergyLevel(), 0, timeManager.getMaxEnergyLevel(), 0, NUMPIXELS);
}

void relayFadeOutLEDs() {
  energyPixelsManager.fadeOutLEDs();
}

void relayDecreaseEnergy() {
  timeManager.decreaseEnergy();
  energyPixelsManager.displayEnergyLevel(mapEnergyLevel());
  Serial.println("Dec. eng. - Value: " + String(timeManager.getEnergyLevel()));

  // If we've passed the update interval, send the passed time to the server
  if (timeManager.getEnergyLevel() != 0 && millis() - lastUpdate >= updateInterval) {
    Serial.println("Decreasing energy - Value: " + String(timeManager.getEnergyLevel()));
    // Send the new energy level to the server only if sendingPassedTime is false
    if (!sendingPassedTime) {
      sendingPassedTime = true;
      bool sentToServer = wifiManager.sendTimeToServer(timeManager.getPassedTime());
      if (sentToServer) {
        Serial.println("Sent passed time to server");
        // Reset the amount of time passed
        timeManager.resetPassedTime();
        lastUpdate = millis();
      } else {
        // Handle failed server communication
        Serial.println("Failed to send passed time to server");
      }
      sendingPassedTime = false;
    }
  }
}

void relaySendPassedTime() {
  int passedTime = timeManager.getPassedTime();
  wifiManager.sendTimeToServer(passedTime);
  // Reset the amount of time passed
  timeManager.resetPassedTime();
}

void setup()
{
  Serial.begin(115200);
  Serial.println("Starting up...");
  //  Set up the built-in LED
  //  Light up the 
  // Connect to Wi-Fi
  wifiManager.connectToWiFi();
  // Sync time with NTP server
  wifiManager.syncTime();
  // Get global game state from server
  // timeManager = getTimeManagerFromServer();
  // Send passed time to server
    // Figure this out 
  // Set up the display - Do this with a separate class later
  energyPixels.begin(); // Initialize the NeoPixel strip
  energyPixels.show(); // Turn all the LEDs off to start

  // Set up the buttons - maybe will move this into a separate class
  
  // Set up our energy level decreasing every second
  tasker.setInterval(relayDecreaseEnergy, 1000);
  // Set up sending the passed time over to the server - default is every 5 minutes
  // tasker.setInterval(relaySendPassedTime, 300000); // double check if we can't use Server Sent Events to trigger this?
  Serial.println("Setup done");
}

void loop(){
  // Serial.println("Looping");
  // Let Tasker do its thing
  tasker.loop();
  encoder.update();

  // INCREASING PASSING TIME STUFF
  // Check if we are overclocked
  if (timeManager.isOverclocked())
  {
    // Check how much we are overclocked, and adjust the multiplier accordingly (like a range of 1.0 to 1.8)

  }
  // Check if we are underclocked
  else if (timeManager.isUnderclocked())
  {
    // Check how much we are underclocked, and adjust the multiplier accordingly (like a range of 0.2 to 1.0)
  }

  // LED STUFF
  // Check if we are winding
  if (encoder.isRotating()) {
    // Wind up the LEDs depending on how after we've been turning the rotary encoder
    int speed = encoder.getRotationSpeed(); // Assuming encoder is accessible here
    windupManager.windupLEDs(speed);
  // Serial.println("Rotating");
    
  // Map the energy level to the LEDs
  // tasker.cancel(relayFadeOutLEDs);
  // energyPixelsManager.displayEnergyLevel(mapEnergyLevel());
  // tasker.setTimeout(relayFadeOutLEDs, 1000);
  }


  // SYNC STUFF WITH THE SERVER STUFF
  // Every 5 minutes, send the passed time to the server and check for events (maybe not needed with Server Sent Events?)
  // if there is an event, update the game state, and display the event on the OLED
  // if there is a maintenance, display the maintenance on the OLED, and listen for the correct input (button combination or piezo hit)
  // Time Management
}