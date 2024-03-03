#include "TimeManager.h"

TimeManager::TimeManager() : energyLevel(0) {}

void TimeManager::increaseEnergy(int amount) {
    energyLevel += amount * baseMultiplier;
    if (energyLevel < 0) energyLevel = 0; // Prevent negative energy
    // Implement clamping energy to a max value if needed
}

void TimeManager::decreaseEnergy() {
    if (energyLevel > 0) energyLevel -= 1;
}

int TimeManager::getEnergyLevel() {
    return energyLevel;
}

void TimeManager::setMaxEnergyLevel(int max) {
    maxEnergyLevel = max;
}

// This make it so that time is passing quicker than normal
void TimeManager::setOverclocked(bool overclock) {
    
}
