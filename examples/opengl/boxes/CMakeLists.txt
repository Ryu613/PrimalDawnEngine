cmake_minimum_required(VERSION 3.27)

project(boxes)

add_executable(boxes boxes.cpp boxes.hpp BoxesRenderer.cpp)

target_link_libraries(boxes PRIVATE pdapp)
