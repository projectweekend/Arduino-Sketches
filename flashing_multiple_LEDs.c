int timeInterval = 100;
int ledPins[] = {7, 8, 12};
int totalPins = 3;


void setup() {                
  // initialize the digital pin as an output.
  for (int i = 0; i < totalPins; ++i)
    {
      pinMode(i, OUTPUT);
    }
}


void loop() {

  for (int i = 0; i < totalPins; ++i)
  {
    digitalWrite(i, HIGH);
    delay(timeInterval);
    digitalWrite(i, LOW);
  }
}
