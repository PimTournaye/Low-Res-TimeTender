#ifndef WiFiManager_h
#define WiFiManager_h

#include <WiFi.h>
#include <HTTPClient.h>
#include "TimeManager.h"

class WiFiManager {
public:
    WiFiManager(const char* ssid, const char* password, const char* serverUrl);
    void connectToWiFi();
    bool sendTimeToServer(int timePassed);
    void syncTime();

private:
    const char* ssid;
    const char* password;
    const char* serverUrl;
    // HTTPClient http;
};

#endif
