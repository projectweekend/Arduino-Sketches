
int sensorPin = 0;


float convertCelsiusToFahrenheit(float c) {
    float f = (c * 9.0 / 5.0) + 32.0;
    return f;
}
 

void setup()
{
    Serial.begin(9600);
}


void loop()
{

    int reading = analogRead(sensorPin);  
 
    float voltage = reading * 5.0;
    voltage /= 1024.0; 
 
    Serial.print(voltage); Serial.println(" volts");
 
    float temperatureC = (voltage - 0.5) * 100 ;
    Serial.print(temperatureC); Serial.println(" degrees C");
 
    float temperatureF = convertCelsiusToFahrenheit(temperatureC);
    Serial.print(temperatureF); Serial.println(" degrees F");
 
    delay(1000);
    
}
