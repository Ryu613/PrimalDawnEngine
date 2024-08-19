cmake_minimum_required(VERSION 3.20)

project(first_world)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(first_world first_world.cpp)

target_link_libraries(first_world PrimalDawnBites)