cmake_minimum_required(VERSION 3.27)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project(
    PrimalDawnEngine 
    VERSION 1.2.0
    LANGUAGES CXX C
    DESCRIPTION "☀PRIMAL DAWN ENGINE"
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PRIMALDAWN_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(LIBRARIES_DIR ${PRIMALDAWN_DIR}/libs)
set(EXTERNALS_DIR ${PRIMALDAWN_DIR}/externals)

# 目前只支持Windows + Vulkan + SDL2 或 Windows + OpenGL + GLFW, 别的组合尚未完成
# VULKAN, OPENGL
set(BACKEND_TYPE "VULKAN" CACHE STRING "specify backend type: VULKAN/OPENGL" FORCE)
# SDL2, GLFW3
set(WSI_TYPE "SDL2" CACHE STRING "specify WSI type: SDL2/GLFW3" FORCE)

add_subdirectory(${PRIMALDAWN_DIR}/engine)

#libs
add_subdirectory(${LIBRARIES_DIR}/application)
add_subdirectory(${LIBRARIES_DIR}/utils)
add_subdirectory(${LIBRARIES_DIR}/ecs)

# samples
add_subdirectory(${PRIMALDAWN_DIR}/samples)
