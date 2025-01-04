cmake_minimum_required(VERSION 3.22)

project(lumavk LANGUAGES CXX)

set(TARGET lumavk)
set(HEADER_DIR include)

set(HEADERS
	include/lumavk/LumaVk.h
)

set(SRCS 
	src/LumaVk.cpp
)

set(LIBS
	vulkan_volk
)

add_library(${TARGET} STATIC ${HEADERS} ${SRCS})

target_link_libraries(${TARGET} PUBLIC ${LIBS})

target_include_directories(${TARGET} PUBLIC ${HEADER_DIR})
