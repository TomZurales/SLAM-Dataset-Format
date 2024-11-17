#pragma once

#include "DistortionModel.h"

class RadialTangential : DistortionModel
{
  float k1;
  float k2;
  float k3;

  float p1;
  float p2;
};