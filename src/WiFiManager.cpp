#include "WiFiManager.h"

// Constructor
WiFiManager::WiFiManager(const char* ssid, const char* password, const char* serverUrl) : ssid(ssid), password(password), serverUrl(serverUrl) {
    
}

void WiFiManager::connectToWiFi() {
    Serial.print("Connecting to WiFi...");
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi");
}

void WiFiManager::syncTime() {
    configTime(0, 0, "pool.ntp.org", "time.nist.gov");
    Serial.println("Waiting for time");
    while (!time(nullptr)) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("Time synced");
}

bool WiFiManager::sendTimeToServer(int timePassed) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.begin(serverUrl); // Make sure serverUrl includes the /state endpoint
        http.addHeader("Content-Type", "application/json");
        
        String payload = "{\"timePassed\": " + String(timePassed) + "}";
        
        int httpResponseCode = http.POST(payload);
        if (httpResponseCode == 200) {
            Serial.println("Data sent successfully");

        } else {
            Serial.print("Error sending data, response code: ");
            Serial.println(httpResponseCode);
        }
        http.end();
        return true;
    } else {
        Serial.println("WiFi not connected");
        return false;
    }
}

