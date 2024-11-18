#pragma once

#include <vector>
#include <string>
#include <algorithm>

#include "SDFSensor.h"
#include "SDFSensorType.h"
#include <memory>

class SDF
{
public:
  std::vector<std::shared_ptr<SDFSensor>> sensors;

public:
  SDF();

  template <typename T>
  std::shared_ptr<T> addSensor(std::string label);

  template <typename T>
  std::shared_ptr<T> getSensorByLabel(std::string label);

  // Returns the number of sensors in the SDF
  int numSensors();
};

template <typename T>
std::shared_ptr<T> SDF::addSensor(std::string label)
{
  static_assert(std::is_base_of<SDFSensor, T>::value, "Passed type is not an SDFSensor");
  std::shared_ptr<T> sensor = std::make_shared<T>(label);
  sensors.push_back(sensor);
  return sensor;
}

template <typename T>
std::shared_ptr<T> SDF::getSensorByLabel(std::string label)
{
  static_assert(std::is_base_of<SDFSensor, T>::value, "Passed type is not an SDFSensor");

  auto it = std::find_if(sensors.begin(), sensors.end(), [&label](const std::shared_ptr<SDFSensor> &sensor)
                         { return sensor->getLabel() == label; });

  if (it != sensors.end())
  {
    if(*it == nullptr)
    {
      return nullptr;
    }
    return std::dynamic_pointer_cast<T>(*it);
  }

  return nullptr;
}