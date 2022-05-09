

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor
unsigned long t, k, s, m ;

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 11, 3, 5, 6);

int stepCount = 0;  // number of steps the motor has taken

void setup() {
  // nothing to do inside the setup
  t = millis();

}

void loop() {
  // read the sensor value:
  // map it to a range from 0 to 100:
  // set the motor speed:

  // step 1/100 of a revolution:
  while (millis() < t + 10000)
  {
    myStepper.setSpeed(100);
    myStepper.step(1);
    k = millis();
  }
  while (millis() < k + 4000)
  {
    s = millis();
  }
  while (millis() < s + 10000)
  {
    myStepper.setSpeed(100);
    myStepper.step(-1);
    m = millis();
  }
  while (millis() < m + 4000)
  {
    t = millis();
  }


}
