cmake_minimum_required(VERSION 3.22)

project(Hello-Triangle)

include_directories(./)

add_executable(hello-triangle main.cpp)

target_sources(hello-triangle PUBLIC HelloTriangle.cpp)

target_link_libraries(hello-triangle PUBLIC pdapp)

include(${PRIMALDAWN}/cmake/CopyDLL.cmake)
