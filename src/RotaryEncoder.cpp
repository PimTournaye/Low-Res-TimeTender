#include "RotaryEncoder.h"

RotaryEncoder::RotaryEncoder(uint8_t pinA, uint8_t pinB, TimeManager &timeManager) : pinA(pinA), pinB(pinB), timeManager(timeManager)
{
  encoder = ESP32Encoder();
  encoder.attachHalfQuad(pinA, pinB);
  encoder.setCount(0);
  lastPosition = 0;
  lastRotating = 0;
  rotating = false;
  this->timeManager = timeManager;
}

void RotaryEncoder::update()
{
  long newPosition = getPosition();
  if (newPosition != lastPosition)
  {
    // Update the the position of the encoder
    lastPosition = newPosition;
    rotating = true;
    lastRotating = millis();
    // Update the game state
    timeManager.increaseEnergy(1);
  }
  // Check if we've stopped rotating
  if (rotating && (millis() - lastRotating) > rotatingTimeout)
  {
    // Update our boolean
    rotating = false;
    // Reset our position
    lastPosition = 0;
  }
}

bool RotaryEncoder::isRotating()
{
  return rotating;
}
