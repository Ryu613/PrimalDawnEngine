cmake_minimum_required(VERSION 3.20)

project(pdapp LANGUAGES CXX)

set(TARGET pdapp)
# 头文件目录
set(HEADER_DIR include/pdapp)

# 头文件
set(HEADERS 
	include/pdapp/Application.h
)
# 源代码
set(SRCS
	src/Application.cpp
)

# 库依赖
set(LIBS
	
)

include_directories(${HEADER_DIR})

add_library(${TARGET} STATIC ${HEADERS} ${SRCS})

target_link_libraries(${TARGET} PUBLIC ${LIBS})

target_include_directories(${TARGET} PUBLIC ${HEADER_DIR})

# 库依赖
