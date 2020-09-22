# Color Sensor Interface for Arduino
This is a simple interface to control a TCS230 / TCS3200 color sensor and identify the detected colors in Arduino, ESP32 or any similar microcontroller.

# The color sensor
The color sensor that this library is based on captures a color in RGB format through its configurable photodiodes. The S0 and S1 pins configure the frequency scaling selection (which is left in a default value of 20% in this library), the S2 and S3 pins configure the photodiode type selection input, which selects the RGB component, and the OUT pin exports the selected signal.

# Usage
## Instalation
Download this repository and add it as a ZIP library in the Arduino IDE (Sketch - Include Library - Include ZIP Library).

## Implemented functions
### Constructor
The constructor of the ColorSensor class has 6 parameters:
* int s0: the pin which S0 is connected in the board;
* int s1: the pin which S1 is connected in the board;
* int s2: the pin which S2 is connected in the board;
* int s3: the pin which S3 is connected in the board;
* int out: the pin which OUT is connected in the board;
* int tolerance: the desired tolerance for color identification (default value: 30).

### begin() (return: void)
Sets the pinout needed for the class and should be called in the setup() function of your main program.

### registerColor(String name, int r, int g, int b) (return: bool)
Registers a named color in the class internal list for later identification (refer to identifyColor) and returns wether the color was registered in the list.

### readColor() (return: color_t)
Activates the sensor and returns a struct (int Red, int Green, int Blue) with the color that was detected.

### identifyColor(color_t color) (return: String)
Identifies the given color and returns its name. This uses the tolerance given in the constructor for the RGB components comparison.

### PS: refer to the example program in the examples folder for a sample program.

# TODO
* Register colors in internal EEPROM.