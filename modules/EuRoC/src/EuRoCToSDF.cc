#include "SDF.h"
#include <yaml-cpp/yaml.h>
#include <sensors/CameraSensor.h>
#include <sensors/ImuSensor.h>

#include <filesystem>

class EuRoCToSDF
{
public:
  std::shared_ptr<SDF> dataset;
  void init(std::string path)
  {
    dataset = std::shared_ptr<SDF>(new SDF());
    if (!std::filesystem::is_directory(path + "/mav0"))
    {
      std::cerr << "Directory " + path + " does not appear to contain a EuRoC MAV dataset. Verify the input path." << std::endl;
      exit(1);
    }
    for (const auto &entry : std::filesystem::directory_iterator(path + "/mav0"))
    {
      if (std::filesystem::is_directory(entry.path()))
      {
        if (std::filesystem::is_regular_file(entry.path().string() + "/sensor.yaml"))
        {
          YAML::Node sensorConfig = YAML::LoadFile(entry.path().string() + "/sensor.yaml");
          createSensor(entry.path(), sensorConfig);
        }
      }
    }
  }
  void createSensor(std::filesystem::path path, YAML::Node sensorConfig)
  {
    std::string sensorType = sensorConfig["sensor_type"].as<std::string>();
    if(sensorType == "camera")
    {
      std::shared_ptr<CameraSensor> sensor = dataset->addSensor<CameraSensor>(path.stem());
      sensor->setDescription(sensorConfig["comment"].as<std::string>());
    } else if(sensorType == "imu")
    {
      std::shared_ptr<ImuSensor> sensor = dataset->addSensor<ImuSensor>(path.stem());
      sensor->setDescription(sensorConfig["comment"].as<std::string>());
    } 
  }
};

int main(int argc, char **argv)
{

  EuRoCToSDF e2sdf = EuRoCToSDF();
  e2sdf.init(argv[1]);

  return 0;
}