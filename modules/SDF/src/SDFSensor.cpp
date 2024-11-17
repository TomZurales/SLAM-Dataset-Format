#include "SDFSensor.h"

SDFSensor::SDFSensor(std::string label)
{
  this->label = label;
}

std::string SDFSensor::getLabel()
{
  return this->label;
}