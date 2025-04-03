cmake_minimum_required(VERSION 3.27)

project(Hello-Triangle)

add_executable(hello-triangle main.cpp HelloTriangle.cpp)

target_link_libraries(hello-triangle PRIVATE pdapp)

#include(${PRIMALDAWN}/cmake/CopyDLL.cmake)
