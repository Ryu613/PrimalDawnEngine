cmake_minimum_required(VERSION 3.20)

project(sandbox)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sandbox sandbox.cpp)

target_link_libraries(sandbox PrimalDawnBites)