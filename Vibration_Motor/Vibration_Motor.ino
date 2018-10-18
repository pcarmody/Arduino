const int motorPin = 3;

void setup()
{
pinMode(motorPin, OUTPUT);
}

void dit()
{
  digitalWrite(motorPin, HIGH);
  delay(100);
  digitalWrite(motorPin, LOW);
  delay(100);
}

void dah()
{
  digitalWrite(motorPin, HIGH);
  delay(500);
  digitalWrite(motorPin, LOW);
  delay(100);
}

void loop()
{
//digitalWrite(motorPin, HIGH);
//delay(1000);
//digitalWrite(motorPin, LOW);
delay(500);
  dit();
  dah();
  dah();
  dit();
  delay(500);
}
