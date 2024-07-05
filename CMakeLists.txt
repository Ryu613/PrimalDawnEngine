cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 作者开发环境:windows10 + vs2022（暂不支持其他OS和环境）
project(
    PrimalDawnEngine 
    LANGUAGES CXX
    DESCRIPTION "PRIMAL DAWN ENGINE version 0.2"
    VERSION 0.2.0
)

# 添加子目录
add_subdirectory(engine)
add_subdirectory("sanbox.exe")
