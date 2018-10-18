#define buzzer 9
#define ButtonPin 7

void setup() {
  // put your setup code here, to run once:
  pinMode(ButtonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(ButtonPin) == HIGH) {
    tone(buzzer, 3141);
  } else {
    noTone(buzzer);
  }
}
