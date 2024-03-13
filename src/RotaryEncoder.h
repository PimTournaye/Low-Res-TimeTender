#ifndef RotaryEncoder_h
#define RotaryEncoder_h

#include <ESP32Encoder.h>
#include <Arduino.h>
#include "TimeManager.h"

class RotaryEncoder
{
public:
  // Constructor
  RotaryEncoder(uint8_t pinA, uint8_t pinB, TimeManager &timeManager);
  // Updates the position of the encoder
  void update();
  // Returns the current position of the encoder
  int getPosition();
  // Returns true if the encoder is currently rotating
  bool isRotating();
  int getRotationSpeed();

private:
  // Constructor stuff
  uint8_t pinA;
  uint8_t pinB;
  ESP32Encoder encoder;
  TimeManager &timeManager;
  // Last position of the encoder (used to detect rotation)
  int lastPosition;
  // Boolean to keep track of whether the encoder is currently rotating
  bool rotating = false;
  // Time of the last rotation
  int lastRotating;
  // Time to wait before we consider the encoder to have stopped rotating
  int rotatingTimeout = 200;
  unsigned long lastRotationTime;
  int rotationSpeed;
};

#endif