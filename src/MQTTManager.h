#ifndef MQTTManager_h
#define MQTTManager_h

#include <PubSubClient.h>
#include <WiFi.h>

class MQTTManager {
public:
    MQTTManager(Client& client, const char* server, uint16_t port, const char* topicBase);
    void connect();
    void loop();
    void publishEnergyUpdate(int level);
    void publishMaintenanceStatus(bool required);
    void publishGameProgress(String progress);
private:
    PubSubClient mqttClient;
    String topicBase;
    void reconnect();
    void callback(char* topic, byte* payload, unsigned int length);
};

#endif
