cmake_minimum_required(VERSION 3.27)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(
    PrimalDawnEngine 
    LANGUAGES CXX C
    DESCRIPTION "☀PRIMAL DAWN ENGINE"
    VERSION 1.2.0
)

# compiler设置s
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 预定义变量
set(PRIMALDAWN_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(LIBRARIES_DIR ${PRIMALDAWN_DIR}/libs)
set(EXTERNALS_DIR ${PRIMALDAWN_DIR}/externals)

# 目前只支持Windows + Vulkan + SDL2 或 Windows + OpenGL + GLFW, 别的组合尚未完成
# VULKAN, OPENGL
set(BACKEND_TYPE "VULKAN" CACHE STRING "specify backend type: VULKAN/OPENGL" FORCE)
# SDL2, GLFW3
set(WSI_TYPE "SDL2" CACHE STRING "specify WSI type: SDL2/GLFW3" FORCE)

# 添加子目录
add_subdirectory(${PRIMALDAWN_DIR}/engine)
add_subdirectory(${LIBRARIES_DIR}/application)
add_subdirectory(${PRIMALDAWN_DIR}/samples)
#add_subdirectory(${PRIMALDAWN_DIR}/examples)
