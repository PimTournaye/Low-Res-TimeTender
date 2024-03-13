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

int RotaryEncoder::getPosition()
{
  return encoder.getCount() / 2;
}

void RotaryEncoder::update()
{
  // Serial.println("DEBUG: Updating encoder + " + String(getPosition())); // Uncomment this line to print the debug message
  unsigned long currentTime = millis();
  // Get the current position of the encoder
  long newPosition = getPosition();
  if (newPosition != lastPosition)
  // Serial.println("Encoder measuring - position: " + String(getPosition()));
  {
    // Serial.println("Rotating - new position: " + String(newPosition));
    unsigned long timeDiff = currentTime - lastRotationTime;
    rotationSpeed = timeDiff == 0 ? INT_MAX : 360 / timeDiff; // Arbitrary speed calculation
    lastPosition = newPosition;
    rotating = true;
    lastRotating = currentTime;
    // Update the game state
    timeManager.increaseEnergy(1);
  }
  // Check if we've stopped rotating
  if (rotating && (millis() - lastRotating) > rotatingTimeout)
  {
    // Update our boolean
    rotating = false;
    // Reset our position
    lastPosition = newPosition;
    // Gradually decrease speed if not rotating
    if (currentTime - lastRotationTime > 100)
    {                                            // No rotation in the last 100 ms
      rotationSpeed = max(0, rotationSpeed - 1); // Slow down gradually
    }
  }
}

bool RotaryEncoder::isRotating()
{
  return rotating;
}

int RotaryEncoder::getRotationSpeed() {
    return rotationSpeed;
}
