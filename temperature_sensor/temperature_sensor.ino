#define aref_voltage 3.3

int sensorPin = 0;


float convertCelsiusToFahrenheit(float c) {
    float f = (c * 9.0 / 5.0) + 32.0;
    return f;
}
 

void setup()
{
    Serial.begin(9600);
    analogReference(EXTERNAL);
}


void loop()
{

    int reading = analogRead(sensorPin);
 
    float voltage = reading * aref_voltage;
    voltage = voltage/1024;
 
    float temperatureC = (voltage - 0.5) * 100;
    Serial.print(temperatureC); Serial.println(" degrees C");
 
    float temperatureF = convertCelsiusToFahrenheit(temperatureC);
    Serial.print(temperatureF); Serial.println(" degrees F");

    Serial.println("=======================");
 
    delay(5000);

}
