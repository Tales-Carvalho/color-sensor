#include "ColorSensor.h"

ColorSensor::ColorSensor(int s0, int s1, int s2, int s3, int out, int tolerance) {
  m_tolerance = tolerance;
  m_s0 = s0;
  m_s1 = s1;
  m_s2 = s2;
  m_s3 = s3;
  m_out = out;
  m_colors_list_size = 0;
}

void ColorSensor::begin() {
  pinMode(m_s0, OUTPUT);
  pinMode(m_s1, OUTPUT);
  pinMode(m_s2, OUTPUT);
  pinMode(m_s3, OUTPUT);
  pinMode(m_out, INPUT);
  digitalWrite(m_s0, HIGH);
  digitalWrite(m_s1, LOW);
}

color_t ColorSensor::readColor() {
  color_t temp_color;
  digitalWrite(m_s2, LOW);
  digitalWrite(m_s3, LOW);
  temp_color.Red = pulseIn(m_out, digitalRead(m_out) == HIGH ? LOW : HIGH);
  digitalWrite(m_s3, HIGH);
  temp_color.Blue = pulseIn(m_out, digitalRead(m_out) == HIGH ? LOW : HIGH);
  digitalWrite(m_s2, HIGH);
  temp_color.Green = pulseIn(m_out, digitalRead(m_out) == HIGH ? LOW : HIGH);
  return temp_color;
}

void ColorSensor::registerColor(String name, int r, int g, int b) {
  if (m_colors_list_size == COLOR_LIST_LIMIT) {
    return;
  }
  m_colors_list_names[m_colors_list_size] = String(name);
  color_t temp_color;
  temp_color.Red = r;
  temp_color.Green = g;
  temp_color.Blue = b;
  m_colors_list[m_colors_list_size++] = temp_color;
}

String ColorSensor::identifyColor(color_t color) {
  String name = "Unidentified";
  for (int i = 0; i < m_colors_list_size; i++) {
    if (abs(color.Red - m_colors_list[i].Red) > m_tolerance) {
      continue;
    }
    if (abs(color.Green - m_colors_list[i].Green) > m_tolerance) {
      continue;
    }
    if (abs(color.Blue - m_colors_list[i].Blue) > m_tolerance) {
      continue;
    }
    name = m_colors_list_names[i];
    break;
  }
  return name;
}
