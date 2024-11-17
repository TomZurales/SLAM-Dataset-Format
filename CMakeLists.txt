cmake_minimum_required(VERSION 3.10)

# Set the project name
project(SlamDatasetFormat)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable all warnings and pedantic mode
# add_compile_options(-Wall -Wextra -pedantic)

# Enable testing for the entire project
find_package(Catch2 3 REQUIRED)

enable_testing()
include(CTest)
include(Catch)

add_subdirectory(modules)