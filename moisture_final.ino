int analogPin = A0;
int moisture;
int percentage;

int map_low = 1013;
int map_high = 320;
void setup() {
  Serial.begin(9600);
}

void loop(){
  moisture = analogRead(analogPin);
  Serial.print("Raw: ");
  Serial.print(moisture);
  percentage = map(moisture, map_low, map_high, 0, 100);
  Serial.print(" | percentage: ");
  Serial.print(percentage);
  Serial.println("%");
}
