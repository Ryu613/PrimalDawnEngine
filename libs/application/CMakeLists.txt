cmake_minimum_required(VERSION 3.27)

project(pdapp LANGUAGES CXX)

set(TARGET pdapp)
# 头文件目录
set(HEADER_DIR include)

# 头文件
set(HEADERS 
	include/application/Application.hpp
)
# 源代码
set(SRCS
	src/Application.cpp
)

# 库依赖
set(LIBS
	engine
)

add_library(${TARGET} STATIC ${HEADERS} ${SRCS})

target_link_libraries(${TARGET} PUBLIC ${LIBS})

target_include_directories(${TARGET} PUBLIC ${HEADER_DIR})
