#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

// color: 1 == RED
// color: 2 == YELLOW
// color: 3 == GREEN

Adafruit_BicolorMatrix matrix = Adafruit_BicolorMatrix();


void animatePixel( int xPos, int yPos, int color, int speed) {
    matrix.drawPixel(xPos, yPos, color);
    matrix.writeDisplay();
    delay(speed);
}


void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");
  
  matrix.begin(0x70);  // pass in the address
}


void loop() {

    matrix.clear();
    matrix.writeDisplay();
    delay(1000);

    animatePixel(3, 3, 3, 300);
    animatePixel(3, 4, 3, 300);
    animatePixel(4, 4, 3, 300);
    animatePixel(4, 3, 3, 300);

}
