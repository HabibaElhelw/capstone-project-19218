#include <Servo.h>
Servo p;
Servo w;
Servo ca;
Servo cc;
void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(8, OUTPUT);
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
  for (int i = 0; i < 180; i++)
  {
    p.write(i);
//    w.write(i);
//    ca.write(i);
//    cc.write(i);
    delay(10);
  }
  for (int i = 180; i > 0; i--)
  {
    p.write(i);
//    w.write(i);
//    ca.write(i);
//    cc.write(i);
    delay(10);
  }

}
