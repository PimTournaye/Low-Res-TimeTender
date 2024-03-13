#include "TimeManager.h"
#include <Arduino.h>

TimeManager::TimeManager() : energyLevel(0) {}

void TimeManager::increaseEnergy(int amount) {
    energyLevel += amount * increaseMultiplier;
    if (energyLevel < 0) energyLevel = 0; // Prevent negative energy
    // Implement clamping energy to a max value if needed
}

void TimeManager::decreaseEnergy() {
    if (energyLevel > 0) {
        int baseDecrease = 1 * decreaseMultiplier;
        // If overclocked, decrease energy faster
        if (overclocked) {
            energyLevel -= baseDecrease * overclockedMultiplier;
            // Adjust passed time property
            passedTime += baseDecrease;

        // If underclocked, decrease energy slower
        } else if (underclocked) {
            energyLevel -= baseDecrease * underclockedMultiplier;
            // Adjust passed time property
            passedTime += baseDecrease;
        } else {
            energyLevel -= 1 * decreaseMultiplier;
            // Adjust passed time property
            passedTime += baseDecrease;
        }
    }
}

int TimeManager::getEnergyLevel() {
    return energyLevel;
}

int TimeManager::getMaxEnergyLevel() {
    return maxEnergyLevel;
}

void TimeManager::setMaxEnergyLevel(int max) {
    maxEnergyLevel = max;
}

// This make it so that time is passing quicker than normal
void TimeManager::setOverclocked(bool overclock) {
    
}

bool TimeManager::isOverclocked() {
    return overclocked;
}

bool TimeManager::isUnderclocked() {
    return underclocked;
}

void TimeManager::setOverclockedEnergyLevel(int level) {
    overclockedEnergyLevel = level;
    overclockedMultiplier = map(overclockedEnergyLevel, 0, maxEnergyLevel, 1, 1.8);
}

void TimeManager::setUnderclockedEnergyLevel(int level) {
    underclockedEnergyLevel = level;
    underclockedMultiplier = map(underclockedEnergyLevel, 0, maxEnergyLevel, 0.2, 1);
}

void TimeManager::resetPassedTime() {
    passedTime = 0;
}

int TimeManager::getPassedTime() {
    return passedTime;
}