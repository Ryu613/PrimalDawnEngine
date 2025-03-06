cmake_minimum_required(VERSION 3.27)

project(engine LANGUAGES CXX)

set(TARGET engine)

# 第三方库依赖
include(${PRIMALDAWN_DIR}/cmake/externals-core.cmake)

set(ENGINE_HEADERS
	include/core/*.hpp
	include/platform/*.hpp
)

set(EXTERNALS
	spdlog::spdlog
	glm::glm
)

set(EXT_HEADERS_DIR)

set(PLATFORM_SRCS)

if(WIN32)
	list(APPEND PLATFORM_SRCS
		src/platform/os/windows/*.hpp
		src/platform/os/windows/*.cpp
	)
endif()

if(USE_SDL2)
	FetchContent_MakeAvailable(sdl2)
	list(APPEND EXTERNALS
		SDL2::SDL2main
		SDL2::SDL2-static
	)
	list(APPEND EXT_HEADERS_DIR
		${sdl2_SOURCE_DIR}/include
	)
	list(APPEND PLATFORM_SRCS
		src/platform/ws/sdl2/*.hpp
		src/platform/ws/sdl2/*.cpp
	)
endif()

if(USE_VULKAN)
	find_package(Vulkan REQUIRED)
	if(NOT Vulkan_FOUND)
		message(FATAL_ERROR "Vulkan Not Found! Project build terminated")
	endif()
	list(APPEND EXTERNALS
		${Vulkan_LIBRARIES}
	)
	list(APPEND EXT_HEADERS_DIR
		${Vulkan_INCLUDE_DIR}
	)
   add_definitions(-DPRIMALDAWN_DRIVER_SUPPORTS_VULKAN)
   	list(APPEND PLATFORM_SRCS
		src/platform/rs/vulkan/*.hpp
		src/platform/rs/vulkan/*.cpp
	)
endif()

file(GLOB engine_core_srcs CONFIGURE_DEPENDS ${ENGINE_HEADERS} ${PLATFORM_SRCS} src/*.cpp)

add_library(${TARGET} STATIC ${engine_core_srcs})

target_link_libraries(${TARGET} PRIVATE ${EXTERNALS})

target_include_directories(${TARGET} PUBLIC include src ${EXT_HEADERS_DIR})
