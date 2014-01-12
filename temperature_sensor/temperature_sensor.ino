#define aref_voltage 3.3

int sensorPin = 0;


float calculateTemp(int rawPinReading) {
    float voltage = (rawPinReading * aref_voltage)/1024;
    float temp = (voltage - 0.5) * 100;
    return temp;
}


float convertCelsiusToFahrenheit(float celsius) {
    float f = (celsius * 9.0 / 5.0) + 32.0;
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
    
    float temperatureC = calculateTemp(reading);
    Serial.print(temperatureC); Serial.println(" degrees C");
 
    float temperatureF = convertCelsiusToFahrenheit(temperatureC);
    Serial.print(temperatureF); Serial.println(" degrees F");

    Serial.println("=======================");
 
    delay(5000);

}
