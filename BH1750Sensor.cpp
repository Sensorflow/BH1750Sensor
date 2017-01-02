//
// Created by alvaro on 8/08/15.
//

#include "BH1750Sensor.h"
#include <Wire.h>
#include <BH1750.h>

BH1750Sensor::BH1750Sensor(String name){
  sensor_ = new BH1750();

  strcpy(name_, name.c_str());

}

const char * BH1750Sensor::getName(){
    return name_;
}

const char * BH1750Sensor::getType(){
    return "BH1750";
}


float * BH1750Sensor::getValues(unsigned int quantities, unsigned int * readValues){
  //if(quantities & ILLUMINANCE) {
    sensor_->begin(BH1750_ONE_TIME_HIGH_RES_MODE_2);
    delay(125);
    uint16_t light = sensor_->readLightLevel();
    values_[0] = (float)light;
    *readValues = 1;
  /*} else {
    values_[0] = 0;
  }*/

  return values_;
}

Sensor * BH1750Sensor::fromConfig(void *data){

  BH1750Sensor *s = new BH1750Sensor();
  return (Sensor *)s;

}
