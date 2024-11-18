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
  
  std::string getLabel();

  std::string getDescription();
  void setDescription(std::string description);

  Eigen::Matrix<float, 4, 4> getTransform();
  void setTransform(Eigen::Matrix<float, 4, 4> transform);
};