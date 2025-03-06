cmake_minimum_required(VERSION 3.27)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(
    PrimalDawnEngine 
    LANGUAGES CXX
    DESCRIPTION "☀PRIMAL DAWN ENGINE"
    VERSION 1.1.0
)

# compiler设置
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 预定义变量
set(PRIMALDAWN_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(LIBRARIES_DIR ${PRIMALDAWN_DIR}/libs)
set(EXTERNALS_DIR ${PRIMALDAWN_DIR}/externals)

# 目前只支持Windows + Vulkan
if(WIN32) 
    option(USE_VULKAN "OS: windows; GRAPHICS API: Vulkan" ON)
    option(USE_SDL2 "Window System: SDL2" ON)
endif()

# 添加子目录
add_subdirectory(${PRIMALDAWN_DIR}/engine)
add_subdirectory(${LIBRARIES_DIR}/application)
#add_subdirectory(${PRIMALDAWN_DIR}/samples)
