#pragma once

#include <utility>
#include  "camera_models/CameraModel.h"
#include "distortion_models/DistortionModel.h"

class CameraSensorParams {
  float framerate;
  std::pair<int, int> resolution;
  CameraModel cameraModel;
  DistortionModel distortionModel;
};