#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H

#include "Arduino.h"

#define COLOR_LIST_LIMIT 10

typedef struct {
  int Red, Green, Blue;
} color_t;

class ColorSensor {
  public:
    ColorSensor(int s0, int s1, int s2, int s3, int out, int tolerance = 30);
    ~ColorSensor() {}
    void begin();
    color_t readColor();
    void registerColor(String name, int r, int g, int b);
    String identifyColor(color_t color);
  private:
    int m_tolerance;
    int m_s0;
    int m_s1;
    int m_s2;
    int m_s3;
    int m_out;
    color_t m_colors_list[COLOR_LIST_LIMIT];
    String m_colors_list_names[COLOR_LIST_LIMIT];
    int m_colors_list_size;
};

#endif
