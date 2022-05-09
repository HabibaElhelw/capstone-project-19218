int motionPin=2;
void setup() {
  Serial.begin(9600);
  pinMode(motionPin, INPUT);
  pinMode(8, OUTPUT);
}

void loop () {
  int motion = digitalRead(motionPin);
  if (motion) {
    Serial.println("Motion detected");
    digitalWrite(8,HIGH);
  } else{
    Serial.println("===noting moves");
    digitalWrite(8,LOW);
  }
  delay(500);
} 
