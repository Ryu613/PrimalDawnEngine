cmake_minimum_required(VERSION 3.22)

project(lumavk LANGUAGES CXX)

set(TARGET lumavk)
set(HEADER_DIR include)

set(HEADERS
	include/lumavk/LumaVK.h
)

set(SRCS src/LumaVK.cpp)

add_library(${TARGET} STATIC ${HEADERS} ${SRCS})

target_include_directories(${TARGET} PUBLIC ${HEADER_DIR})
