#include "MQTTManager.h"

MQTTManager::MQTTManager(Client& client, const char* server, uint16_t port, const char* topicBase)
: mqttClient(client), topicBase(topicBase) {
    mqttClient.setServer(server, port);
    mqttClient.setCallback([this](char* topic, byte* payload, unsigned int length) { this->callback(topic, payload, length); });
}

void MQTTManager::connect() {
    while (!mqttClient.connected()) {
        Serial.println("Connecting to MQTT...");
        if (mqttClient.connect("ESP32Client")) { 
            Serial.println("connected");
            // Subscribe to control commands here if necessary
        } else {
            Serial.print("failed, rc=");
            Serial.print(mqttClient.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}

void MQTTManager::loop() {
    if (!mqttClient.connected()) {
        reconnect();
    }
    mqttClient.loop();
}

void MQTTManager::publishEnergyUpdate(int level) {
    mqttClient.publish((topicBase + "/energy").c_str(), String(level).c_str());
}

void MQTTManager::publishMaintenanceStatus(bool required) {
    mqttClient.publish((topicBase + "/maintenance").c_str(), required ? "1" : "0");
}

void MQTTManager::publishGameProgress(String progress) {
    mqttClient.publish((topicBase + "/progress").c_str(), progress.c_str());
}

void MQTTManager::reconnect() {
    // Implement reconnection logic similar to connect()
}

void MQTTManager::callback(char* topic, byte* payload, unsigned int length) {
    // Handle incoming messages
}
