int inputPin = 0;


void setup()
{
    Serial.begin(9600);
}


void loop()
{
    float reading = analogRead(inputPin);

    Serial.print(reading);

    if (reading < 10) {
        Serial.println(" = DARK");
    } else if(reading < 200) {
        Serial.println(" = DIM");
    } else if (reading < 500) {
        Serial.println(" = LIGHT");
    } else if (reading < 800) {
        Serial.println(" = BRIGHT");
    } else {
        Serial.println(" = VERY BRIGHT");
    }

    delay(2000);
}
