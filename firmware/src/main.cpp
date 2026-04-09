#include <Arduino.h>
// #include <HardwareSerial.h>
#include <loadcell.h>
// #include <KTransFunc.h>

#define SCK1 18
#define SCK2 17
#define DT1 19
#define DT2 16
#define SCALE1 948
#define SCALE2 948

double sensor_value1 = 0;
double sensor_value2 = 0;

Loadcell loadcell1 = Loadcell(SCK1, DT1, SCALE1);
Loadcell loadcell2 = Loadcell(SCK2, DT2, SCALE2);

void setup()
{
  Serial.begin(115200);
  loadcell1.init();
  loadcell2.init();
  loadcell1.reset_zero_offset();
  loadcell2.reset_zero_offset();
}

void loop()
{
  sensor_value1 = abs(loadcell1.read_value());
  sensor_value2 = abs(loadcell2.read_value());
  Serial.print("Load1: ");Serial.print(sensor_value1);
  Serial.print("\t");
  Serial.print("Load2: ");Serial.println(sensor_value2);
  // delay(20); // optional
}