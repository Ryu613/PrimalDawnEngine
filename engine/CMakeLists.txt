cmake_minimum_required(VERSION 3.20)

project(engine CXX)

set(TARGET engine)
# 头文件目录
set(HEADER_DIR include)

# 头文件
set(HEADERS 
	include/core/Engine.h
)
# 源代码
set(SRCS
	src/Engine.cpp
)

include_directories(${HEADER_DIR})
include_directories(src)

add_library(${TARGET} STATIC ${HEADERS} ${SRCS})

target_include_directories(${TARGET} PUBLIC ${HEADER_DIR})

# 库依赖
