cmake_minimum_required(VERSION 3.20)

project(DAWN)

# compiler设置
set(CXX_STANDARD "-std=c++17")
if(WIN32)
    set(CXX_STANDARD "/std:c++17")
    # 数学预定义常量
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_USE_MATH_DEFINES=1")
endif()

if(MSVC)
    set(CXX_STANDARD "/std:c++latest")
    # 禁止编译器警告，并更新标识为C++最新版
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_STANDARD} /W0 /Zc:__cplusplus")
endif()

project(
    PrimalDawnEngine 
    LANGUAGES CXX
    DESCRIPTION "☀PRIMAL DAWN ENGINE"
    VERSION 1.0.0
)

# 库地址
set(LIBRARIES ${CMAKE_CURRENT_SOURCE_DIR}/libs)
set(PRIMALDAWN ${CMAKE_CURRENT_SOURCE_DIR})

# current only support windows vulkan
if(WIN32) 
    option(SUPPORT_VULKAN "OS: windows; GRAPHICS API: Vulkan" ON)
endif()

# 添加子目录
add_subdirectory(${PRIMALDAWN}/engine)
add_subdirectory(${PRIMALDAWN}/samples)
add_subdirectory(${LIBRARIES}/pdapp)
add_subdirectory(3rd_party)

if(SUPPORT_VULKAN)
    add_subdirectory(${LIBRARIES}/lumavk)
endif()
