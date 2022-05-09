#include <Servo.h>
Servo p;
Servo w;
Servo ca;
Servo cc;

int motionPin = 2;

int analogPin = A0;
int moisture;
int percentage;
int map_low = 1013;
int map_high = 320;
int pTime = 10000;
int wTime = 25000;
int caTime = 13500;
int ccTime = 1500;
int motion;


#include <Stepper.h>

const int stepsPerRevolution = 200;
unsigned long t, k, s, m ;
Stepper myStepper(stepsPerRevolution, 11, 3, 5, 6);
int stepCount = 0;

void setup() {
  Serial.begin(9600);
  p.attach(3);
  w.attach(5);
  ca.attach(6);
  cc.attach(9);
  p.write(0);
  w.write(0);
  ca.write(0);
  cc.write(0);
}

void loop() {
  servoMotor();
  mositureSensor();
  if (percentage > 25)
  {
    pTime -= 2;
  } else if (percentage < 6)
  {
    pTime += 2;
  }
  else
  {
    stepperMotor();
    motionSensor();
    if (motion) {
      caTime += 2;
    }
    else
    {
      while (1)
      {
      }
    }
  }
}

void motionSensor()
{
  motion = digitalRead(motionPin);

}
void servoMotor()
{
  for (int i = 0; i < 180; i++)
  {
    p.write(i);
    w.write(i);
    ca.write(i);
    cc.write(i);
    delay(10);
  }
  delay(ccTime);
  for (int i = 180; i > 0; i--)
  {
    cc.write(i);
    delay(10);
  }
  delay(caTime);
  for (int i = 180; i > 0; i--)
  {
    ca.write(i);
    delay(10);
  }
  delay(pTime);
  for (int i = 180; i > 0; i--)
  {
    p.write(i);
    delay(10);
  }
  delay(wTime);
  for (int i = 180; i > 0; i--)
  {
    w.write(i);
    delay(10);
  }
}
void mositureSensor()
{
  moisture = analogRead(analogPin);
  Serial.print("Raw: ");
  Serial.print(moisture);
  percentage = map(moisture, map_low, map_high, 0, 100);
  Serial.print(" | percentage: ");
  Serial.print(percentage);
  Serial.println("%");
  t = millis();
}
void stepperMotor()
{
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
  }
}
