#pragma once

#include <string>
#include "SDFSensorType.h"

class SDFSensor
{
private:
  std::string label;
  std::string descripton;

public:
  SDFSensor(std::string label);
  virtual ~SDFSensor() = default;
  
  SDFSensorType getType();
  std::string getLabel();

  std::string getDescription();
  std::string setDescription();
};