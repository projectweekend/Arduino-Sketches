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

    // Draw center box
    animatePixel(3, 3, 3, 300);
    animatePixel(3, 4, 3, 300);
    animatePixel(4, 4, 3, 300);
    animatePixel(4, 3, 3, 300);

    // Draw top left corner box
    animatePixel(7, 0, 1, 300);
    animatePixel(7, 1, 1, 300);
    animatePixel(6, 1, 1, 300);
    animatePixel(6, 0, 1, 300);

    // Draw top right corner box
    animatePixel(7, 7, 1, 300);
    animatePixel(7, 6, 1, 300);
    animatePixel(6, 6, 1, 300);
    animatePixel(6, 7, 1, 300);    

}
