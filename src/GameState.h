#ifndef GameState_h
#define GameState_h

class GameState {
public:
    enum Mode { CHRONOS, KAIROS };
    GameState();
    void updateEnergy(int change);
    void setMode(Mode mode);
    int getEnergyLevel() const;
    Mode getCurrentMode() const;

private:
    int energyLevel;
    Mode currentMode;
};

#endif