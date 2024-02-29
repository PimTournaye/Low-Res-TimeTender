#ifndef EventManager_h
#define EventManager_h

#include "GameState.h"
#include <PubSubClient.h>

class EventManager {
public:
    EventManager(GameState& gameState, PubSubClient& mqttClient);
    void checkForEvents();
    void syncState();

private:
    GameState& gameState;
    PubSubClient& mqttClient;
};

#endif