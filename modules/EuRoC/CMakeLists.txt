find_library(yaml-cpp YAML)

add_executable(EuRoCToSDF src/EuRoCToSDF.cc)
target_link_libraries(EuRoCToSDF
  PUBLIC sdf
  PUBLIC yaml-cpp
)