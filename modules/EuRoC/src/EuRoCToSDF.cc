#include "SDF.h"
#include <yaml-cpp/yaml.h>

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
          createSensor(entry.path().stem(), sensorConfig);
        }
      }
    }
  }
  void createSensor(std::string label, YAML::Node sensorConfig)
  {
    std::cout << "Label: " << label << std::endl;
    std::string sensorType = sensorConfig["sensor_type"].as<std::string>();
    if(sensorType == "camera")
    {
      dataset->addSensor<CameraSensor>(label);
    }
  }
};

int main(int argc, char **argv)
{

  EuRoCToSDF e2sdf = EuRoCToSDF();
  e2sdf.init(argv[1]);

  return 0;
}