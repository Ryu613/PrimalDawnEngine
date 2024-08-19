cmake_minimum_required(VERSION 3.20)

project(sample0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sample0 "sample_0.cpp")

target_link_libraries(sample0 PrimalDawnBites)