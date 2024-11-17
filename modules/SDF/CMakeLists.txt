find_package(OpenCV 4 REQUIRED)
find_package(Eigen3 3 REQUIRED)

add_library(sdf SHARED
  src/SDF.cpp
  src/SDFSensor.cpp
  src/sensors/CameraSensor.cpp
)

target_include_directories(sdf
  PUBLIC include
)

target_include_directories(sdf
  PUBLIC ${OpenCV_INCLUDE_DIRS}
  PUBLIC ${Eigen3_INCLUDE_DIRS}
)

target_link_libraries(sdf
  PUBLIC ${OpenCV_LIBS}
  PUBLIC ${Eigen3_LIBS}
)

# Testing
add_executable(TestSDF test/testSDF.cpp)
target_link_libraries(TestSDF PRIVATE sdf)
target_link_libraries(TestSDF PRIVATE Catch2::Catch2WithMain)

catch_discover_tests(TestSDF)