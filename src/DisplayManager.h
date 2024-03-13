// #ifndef DisplayManager_h
// #define DisplayManager_h

// #include "TimeManager.h"
// // #include <Adafruit_GFX.h>
// // #include <Adafruit_SSD1306.h>
// #include <Adafruit_NeoPixel.h>

// // Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


// class DisplayManager {
// public:
//     DisplayManager(TimeManager& timeManager, Adafruit_NeoPixel& pixels1, Adafruit_NeoPixel& pixels2, U8G2& oledDisplay);
//     void updateDisplay();
//     void updateEnergyStick

// private:
//     TimeManager& timeManager;
//     Adafruit_NeoPixel& pixels1;
//     Adafruit_NeoPixel& pixels2;
// };

// #endif

// if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
//     Serial.println(F("SSD1306 allocation failed"));
//     for(;;);
//   }
//   delay(2000);
//   display.clearDisplay();

//   display.setTextSize(3);
//   display.setTextColor(WHITE);
//   display.setCursor(0, 10);
//   // Display static text
//   display.println("Hello, world!");
//   display.display(); 