#include <Servo.h>
#include "Defines.h"
#include "PCA9685Emulator.h"

PCA9685Emulator pwmEmulation;

Servo svoSteer;
Servo svoThrottle;

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_STEER_OUT, OUTPUT);
  svoSteer.attach(PIN_STEER_OUT);
  pinMode(PIN_THROTTLE_OUT, OUTPUT);
  svoThrottle.attach(PIN_THROTTLE_OUT);
  pwmEmulation.begin(PCA9685_I2C_ADDRESS);
}

void loop() {
  // put your main code here, to run repeatedly:
  pwmEmulation.step(millis());
  svoSteer.writeMicroseconds(pwmEmulation.readChannelUs(0));
  svoThrottle.writeMicroseconds(pwmEmulation.readChannelUs(1));
}
