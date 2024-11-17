#pragma once

#include "SDFSensor.h"
#include "SDFSensorType.h"
#include <opencv2/opencv.hpp>
#include "params/CameraSensorParams.h"

class CameraSensor : public SDFSensor
{

public:
  struct StampedImage
  {
    cv::Mat image;
    uint64_t stamp;

    bool operator<(const StampedImage &other) const
    {
      return stamp < other.stamp;
    }

    bool operator>(const StampedImage &other) const
    {
      return stamp > other.stamp;
    }
  };
  CameraSensor(std::string label);

  int addImage(cv::Mat image, uint64_t stamp_ns);

  StampedImage getNextImage();

private:
  std::priority_queue<StampedImage> distorted_images;
};