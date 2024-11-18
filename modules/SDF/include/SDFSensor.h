#pragma once

#include <string>
#include <eigen3/Eigen/Core>

#include "SDFSensorType.h"

class SDFSensor
{
private:
  std::string label;
  std::string descripton;
  Eigen::Matrix<float, 4, 4> transform = Eigen::Matrix<float, 4, 4>::Identity();

public:
  SDFSensor(std::string label);
  virtual ~SDFSensor() = default;
  
  std::string getLabel(){return label;};

  std::string getDescription(){return descripton;};
  void setDescription(std::string description){description = description;};

  Eigen::Matrix<float, 4, 4> getTransform();
  void setTransform(Eigen::Matrix<float, 4, 4> transform);
};