//
// Created by alvaro on 8/08/15.
//
#include "Sensor.h"
#include "BH1750.h"

#ifndef BH1750_SENSOR_H
#define BH1750_SENSOR_H


class BH1750Sensor: public Sensor {
public:
  BH1750Sensor(String name = "BH1750");
  //BH1750Sensor();
  const char* getName();
  float* getValues(unsigned int quantities, unsigned int * readValues);
  static const char* getType();
  static Sensor* fromConfig(void *);
private:
  char name_[10];
  float values_[2];
  BH1750 *sensor_;
};


#endif //SENSOR_MONITOR_DEVICE_H
