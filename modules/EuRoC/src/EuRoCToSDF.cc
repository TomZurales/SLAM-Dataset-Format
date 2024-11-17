#include "SDF.h"
#include <yaml-cpp/yaml.h>

#include <filesystem>

int main(int argc, char** argv)
{
  std::shared_ptr<SDF> dataset(new SDF());

  std::string path = argv[1];
  if(! std::filesystem::is_directory(path + "/mav0"))
  {
    std::cerr << "Directory " + path + " does not appear to contain a EuRoC MAV dataset. Verify the input path." << std::endl;
    exit(1);
  }
  for(const auto & entry : std::filesystem::directory_iterator(path + "/mav0"))
  {
    if(std::filesystem::is_directory(entry.path()))
    {
      if(std::filesystem::is_regular_file(entry.path().string() + "/sensor.yaml")){
        YAML::Node sensorConfig = YAML::LoadFile(entry.path().string() + "/sensor.yaml");
        for (YAML::const_iterator it = sensorConfig.begin(); it != sensorConfig.end(); ++it) {
          std::cout << it->first.as<std::string>() << ": " << it->second << std::endl;
        }
      }
    }
    std::cout << entry.path() << std::endl;
  }

  dataset->addSensor<CameraSensor>("cam0");
  return 0;
}