#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"


Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

int RANDOM_NUMBER;

static const uint8_t PROGMEM
  one_bmp[] =
  { B00000000,
	B00000000,
	B00000000,
	B00011000,
	B00011000,
	B00000000,
	B00000000,
	B00000000 },
  two_bmp[]=
  { B00000000,
	B01100000,
	B01100000,
	B00000000,
	B00000000,
	B00000110,
	B00000110,
	B00000000 },
  three_bmp[]=
  { B11000000,
	B11000000,
	B00000000,
	B00011000,
	B00011000,
	B00000000,
	B00000011,
	B00000011 },
  four_bmp[]=
  { B00000000,
	B01100110,
	B01100110,
	B00000000,
	B00000000,
	B01100110,
	B01100110,
	B00000000 },
  five_bmp[]=
  { B11000011,
	B11000011,
	B00000000,
	B00011000,
	B00011000,
	B00000000,
	B11000011,
	B11000011 },
  six_bmp[]=
  { B01100110,
	B01100110,
	B00000000,
	B01100110,
	B01100110,
	B00000000,
	B01100110,
	B01100110 };


void setup()
{
	randomSeed(analogRead(0));
	Serial.begin(9600);
	matrix.begin(0x70);
}


void loop()
{

	if (!RANDOM_NUMBER) {

		RANDOM_NUMBER = random(1, 7);
		matrix.clear();
		delay(1000);

		switch (RANDOM_NUMBER) {

			case 1:
				matrix.drawBitmap(0, 0, one_bmp, 8, 8, LED_GREEN);
				break;

			case 2:
				matrix.drawBitmap(0, 0, two_bmp, 8, 8, LED_GREEN);
				break;

			case 3:
				matrix.drawBitmap(0, 0, three_bmp, 8, 8, LED_GREEN);
				break;

			case 4:
				matrix.drawBitmap(0, 0, four_bmp, 8, 8, LED_GREEN);
				break;

			case 5:
				matrix.drawBitmap(0, 0, five_bmp, 8, 8, LED_GREEN);
				break;

			case 6:
				matrix.drawBitmap(0, 0, six_bmp, 8, 8, LED_GREEN);
				break;

		}

		matrix.writeDisplay();

	}

}
