#include "WiFiManager.h"

WiFiManager::WiFiManager(const char* ssid, const char* password, const char* serverUrl)
: ssid(ssid), password(password), serverUrl(serverUrl) {}

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

void WiFiManager::sendTimeToServer(int timePassed) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.begin(serverUrl); // Specify the API endpoint
        http.addHeader("Content-Type", "application/json");
        
        // Prepare your JSON payload string
        String payload = "{\"timePassed\": " + String(timePassed) + "}";
        
        int httpResponseCode = http.POST(payload);
        if (httpResponseCode > 0) {
            Serial.println("Data sent successfully");
        } else {
            Serial.println("Error sending data");
        }
        http.end();
    } else {
        Serial.println("WiFi not connected");
    }
}
