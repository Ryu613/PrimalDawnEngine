cmake_minimum_required(VERSION 3.27)

add_executable(triangle main.cpp)
target_link_libraries(triangle PRIVATE application)

#include(${PRIMALDAWN}/cmake/CopyDLL.cmake)
