#include "ColorSensor.h"

#define S0 15
#define S1 2
#define S2 4
#define S3 5
#define OUT 18
#define TOLERANCE 30

ColorSensor myColorSensor(S0, S1, S2, S3, OUT, TOLERANCE);

void setup()
{
  myColorSensor.begin();
  
  // Manually registered colors - change this in your own program based on your sensor output
  myColorSensor.registerColor("White", 50, 50, 50);
  myColorSensor.registerColor("Blue", 100, 100, 50);
  myColorSensor.registerColor("Red", 50, 150, 150);
  myColorSensor.registerColor("Yellow", 100, 100, 50);
  myColorSensor.registerColor("Black", 200, 200, 200);
  
  Serial.begin(9600);
}
 
void loop()
{
  //Color detection and identification
  color_t color = myColorSensor.readColor();
  String colorName = myColorSensor.identifyColor(color);
  
  //Showing values in Serial monitor
  Serial.print("Red: ");
  Serial.print(color.Red, DEC);
  Serial.print("; Green: ");
  Serial.print(color.Green, DEC);
  Serial.print("; Blue: ");
  Serial.println(color.Blue, DEC);
  Serial.println("Color: " + colorName);
 
  delay(500);
}
