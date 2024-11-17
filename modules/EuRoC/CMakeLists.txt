find_package(yaml REQUIRED)

add_executable(EuRoCToSDF src/EuRoCToSDF.cc)
target_link_libraries(EuRoCToSDF PUBLIC sdf)