#pragma once

#include "CameraModel.h"

class Pinhole : CameraModel
{
  int fu;
  int fv;
  int cu;
  int cv;  
};