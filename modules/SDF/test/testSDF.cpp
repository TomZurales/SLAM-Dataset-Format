#include <catch2/catch_test_macros.hpp>

#include <cstdint>
#include "SDF.h"
#include <sensors/CameraSensor.h>

TEST_CASE("Camera Setup", "[sdf]")
{
  SDF *dataset = new SDF();

  // New SDF objects have 0 sensors defined
  REQUIRE(dataset->numSensors() == 0);

  // Adding a camera sensor should increase the number of sensors to 1
  dataset->addSensor<CameraSensor>("left");
  REQUIRE(dataset->numSensors() == 1);
  dataset->addSensor<CameraSensor>("right");
  REQUIRE(dataset->numSensors() == 2);
  // dataset->addSensor<InertialSensor>("imu");
  
  std::string imageName = "1403637130538319104.png";
  cv::Mat image = cv::imread("/home/tom/workspace/slam_dataset_format/modules/SDF/test/assets/" + imageName);
  cv::imshow("image", image);
  cv::waitKey(0);
  dataset->getSensorByLabel<CameraSensor>("left")->addImage(image, 1403637130538319104);

  cv::imshow("image", dataset->getSensorByLabel<CameraSensor>("left")->getNextImage().image);
  cv::waitKey(0);

  // Getting the sensor by label should return a Camera
  // SDFSensor sensor = dataset->getSensorByLabel("left");
  // REQUIRE(sensor.getType() == SDFSensorType::CAMERA);

}