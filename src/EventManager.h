#ifndef EventManager_h
#define EventManager_h

#include "TimeManager.h"

class EventManager {
public:
    EventManager(TimeManager& timeManager, PubSubClient& mqttClient);
    void checkForEvents();
    void syncState();

private:
    TimeManager& timeManager;
    PubSubClient& mqttClient;
};

#endif