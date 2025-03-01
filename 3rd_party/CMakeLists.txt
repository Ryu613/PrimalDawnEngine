cmake_minimum_required(VERSION 3.27)

project(3rd-party LANGUAGES C CXX)

# glm
add_library(glm INTERFACE)
set(GLM_DIR ${CMAKE_CURRENT_SOURCE_DIR}/glm)
target_sources(glm INTERFACE ${GLM_DIR}/glm/glm.hpp)
target_include_directories(glm SYSTEM INTERFACE ${GLM_DIR})

target_compile_definitions(glm INTERFACE
# 允许向量分量重排和部分获取
	GLM_FORCE_SWIZZLE
# 强制使用弧度，避免某些平台默认用角度问题
	GLM_FORCE_RADIANS
# 强制对向量或矩阵初始化赋予默认值
	GLM_FORCE_CTOR_INIT
)

#fmt
add_subdirectory(fmt)
set_property(TARGET fmt PROPERTY FOLDER "3rd-party")

# spdlog
# 统一使用同个fmt库
set(SPDLOG_FMT_EXTERNAL ON)
add_subdirectory(spdlog)
# VS工程把此库放在3rd-party文件夹下
set_property(TARGET spdlog PROPERTY FOLDER "3rd-party")

# SDL2
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
add_subdirectory(sdl2)
add_library(sdl2 INTERFACE)
target_link_libraries(sdl2 INTERFACE SDL2::SDL2main SDL2::SDL2-static)
target_include_directories(sdl2 SYSTEM INTERFACE ${THIRD_PARTY}/sdl2/include)
set_property(TARGET sdl2 PROPERTY FOLDER "3rd-party")
