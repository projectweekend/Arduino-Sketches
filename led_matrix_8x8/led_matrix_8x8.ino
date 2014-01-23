#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"


Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();

// color: 1 == RED
// color: 2 == YELLOW
// color: 3 == GREEN

void rippleHorizontalLine(int x, int y, int length, int color, int speed) {

    for (int i = 1; i < length + 1; i++) {
        matrix.drawRect(x, y, i, 1, color);
        matrix.writeDisplay();
        delay(speed);   
    }

}


void rippleVerticleLine(int x, int y, int length, int color, int speed) {

    for (int i = 1; i < length + 1; i++) {
        matrix.drawRect(x, y, 1, i, color);
        matrix.writeDisplay();
        delay(speed);   
    }

}


void setup() {
  Serial.begin(9600);
  matrix.begin(0x70);
}


void loop() {

  matrix.clear();

  rippleHorizontalLine(0, 0, 8, 1, 100);
  rippleHorizontalLine(0, 7, 8, 1, 100);
  rippleVerticleLine(7, 0, 8, 1, 100);
  rippleVerticleLine(0, 0, 8, 1, 100);

  rippleHorizontalLine(1, 1, 6, 2, 100);
  rippleHorizontalLine(1, 6, 6, 2, 100);
  rippleVerticleLine(6, 1, 6, 2, 100);
  rippleVerticleLine(1, 1, 6, 2, 100);

  rippleHorizontalLine(2, 2, 4, 3, 100);
  rippleHorizontalLine(2, 5, 4, 3, 100);
  rippleVerticleLine(5, 2, 4, 3, 100);
  rippleVerticleLine(2, 2, 4, 3, 100);

  rippleHorizontalLine(3, 3, 2, 1, 100);
  rippleHorizontalLine(3, 4, 2, 1, 100);  

  delay(1000);  

}
