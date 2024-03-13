#ifndef TimeManager_h
#define TimeManager_h

class TimeManager {
public:
    TimeManager();
    // Returns the current energy level
    int getEnergyLevel();
    // Increases the energy level by the given amount
    void increaseEnergy(int amount);
    // Decreases the energy level by the given amount
    void decreaseEnergy();
    // Sets the maximum energy level that we can achieve currently
    void setMaxEnergyLevel(int max);
    // Returns the maximum energy level
    int getMaxEnergyLevel();
    // This make it so that time is passing quicker than normal
    void setOverclocked(bool overclock);
    // Set the amount of overclocked energy, indicating the overclocked multiplier
    void setOverclockedEnergyLevel(int level);
    // This make it so that time is passing slower than normal
    void setUnderclocked(bool underclock);
    // Set the amount of underclocked energy, indicating the underclocked multiplier
    void setUnderclockedEnergyLevel(int level);
    // Returns if the clock is currently overclocked
    bool isOverclocked();
    // Returns if the clock is currently underclocked
    bool isUnderclocked();
    void resetPassedTime();
    int getPassedTime();

private:
    // Current energy level of the clock
    int energyLevel;
    // Maximum energy level of the clock, which can be increased. Default is 3600, which is 1 hour
    int maxEnergyLevel = 3600;
    // The base multiplier for the time passing
    int increaseMultiplier = 10;
    int decreaseMultiplier = 1;
    // Overclocked and underclocked stuff
    bool overclocked = false;
    // The amount of overclocked energy, indicating the overclocked multiplier
    int overclockedEnergyLevel = 0;
    // The multiplier for the overclocked time passing, default is a range of 1.0 to 1.8
    int overclockedMultiplier = 1;
    bool underclocked = false;
    // The amount of underclocked energy, indicating the underclocked multiplier
    int underclockedEnergyLevel = 0;
    // The multiplier for the underclocked time passing, default is a range of 0.2 to 1.0
    int underclockedMultiplier = 1;

    int passedTime = 0;
    int remainingEnergy = 0;
};

#endif