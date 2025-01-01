cmake_minimum_required(VERSION 3.22)

project(engine LANGUAGES CXX)

set(TARGET engine)
# 头文件目录
set(HEADER_DIR include)

# 头文件
set(HEADERS 
	include/core/Engine.h
	include/core/util/Logging.h
	include/platform/Window.h
	include/platform/SDLWindow.h

)
# 源代码
set(SRCS
	src/Engine.cpp
	src/Window.cpp
	src/Logging.cpp
	src/SDLWindow.cpp
)

set(LIBS
	spdlog::spdlog
	sdl2
)

include_directories(${HEADER_DIR})

add_library(${TARGET} STATIC ${HEADERS} ${SRCS})

target_link_libraries(${TARGET} PUBLIC ${LIBS})

target_include_directories(${TARGET} PUBLIC ${HEADER_DIR})
