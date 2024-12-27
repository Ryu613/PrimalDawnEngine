cmake_minimum_required(VERSION 3.20)

project(Hello-Triangle)

add_executable(hello-triangle HelloTriangle.cpp)

target_link_libraries(hello-triangle private pdapp)
