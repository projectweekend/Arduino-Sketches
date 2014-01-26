#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

// color: 1 == RED
// color: 2 == YELLOW
// color: 3 == GREEN

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();


void animatePixel(int xPos, int yPos, int color, int speed) {
    matrix.drawPixel(xPos, yPos, color);
    matrix.writeDisplay();
    delay(speed);
}


void animateSmallSquare(int xPos, int yPos, int color, int speed) {
    matrix.fillRect(xPos, yPos, 2, 2, color);
    matrix.writeDisplay();
    delay(speed);    
}


void setup() {
  Serial.begin(9600);
  matrix.begin(0x70);
}


void loop() {

    matrix.clear();
    matrix.writeDisplay();
    delay(1000);

    // Draw center box
    animatePixel(3, 3, 3, 300);
    animatePixel(3, 4, 3, 300);
    animatePixel(4, 4, 3, 300);
    animatePixel(4, 3, 3, 300);

    // Draw top left corner box
    animatePixel(7, 0, 1, 100);
    animatePixel(7, 1, 1, 100);
    animatePixel(6, 1, 1, 100);
    animatePixel(6, 0, 1, 100);

    // Draw top right corner box
    animatePixel(7, 7, 1, 100);
    animatePixel(7, 6, 1, 100);
    animatePixel(6, 6, 1, 100);
    animatePixel(6, 7, 1, 100);

    // Draw bottom right corner box
    animatePixel(0, 7, 1, 100);
    animatePixel(0, 6, 1, 100);
    animatePixel(1, 6, 1, 100);
    animatePixel(1, 7, 1, 100);

    // Draw bottom left corner box
    animatePixel(0, 0, 1, 100);
    animatePixel(0, 1, 1, 100);
    animatePixel(1, 1, 1, 100);
    animatePixel(1, 0, 1, 100);

    // Draw boxes half way between corners
    animateSmallSquare(3, 0, 2, 400);
    animateSmallSquare(6, 3, 2, 400);
    animateSmallSquare(3, 6, 2, 400);
    animateSmallSquare(0, 3, 2, 400);

    delay(3000);

}
