#include "sensors/CameraSensor.h"

CameraSensor::CameraSensor(std::string label): SDFSensor(label)
{
  
}

int CameraSensor::addImage(cv::Mat image, uint64_t stamp_ns)
{
  distorted_images.emplace(StampedImage{image, stamp_ns});
  return 0;
}

CameraSensor::StampedImage CameraSensor::getNextImage()
{
  return distorted_images.top();
}