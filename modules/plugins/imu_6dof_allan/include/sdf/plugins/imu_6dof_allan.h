#pragma once

#include <string>
#include <vector>
#include <memory>
#include <stdfloat>
#include <filesystem>
#include <iostream>

#include "sdf/sensor.h"
#include "sdf/blob.h"
#include "sdf/transform.h"

namespace SDF
{
  namespace sensors
  {
    class IMU6DOFAllan : public Sensor
    {
    public:
      class Data : public Sensor::Data
      {
      public:
        float ax;
        float ay;
        float az;
        float wx;
        float wy;
        float wz;

        void show() const override
        {
        }

        bool load() override
        {
          return true;
        }

        Blob serialize() override
        {
          Blob blob = Blob(24);
          blob << timestamp;
          blob << ax;
          blob << ay;
          blob << az;
          blob << wx;
          blob << wy;
          blob << wz;
          return blob;
        }
      };

      std::string notes;
      float rate;

      float gyroscope_noise_density;
      float gyroscope_random_walk;
      float accelerometer_noise_density;
      float accelerometer_random_walk;

      std::vector<std::shared_ptr<Sensor::Data>> getData() const override;

      void show() const override;

      Blob serialize() override;
    };
  }
}