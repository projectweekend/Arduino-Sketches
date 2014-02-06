int mainDelayValue = 200;
int loopDelayValue = 5;


void setup()
{
    pinMode(3, OUTPUT);
}


void loop()
{
    for(int a = 0; a < 256; a++)
    {
        analogWrite(3, a);
        delay(loopDelayValue);
    }

    for(int a = 255; a >= 0 ; a--)
    {
        analogWrite(3, a);
        delay(loopDelayValue);        
    }

    delay(mainDelayValue);
}
