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
	fmt
	spdlog::spdlog
	glm
)

set(EXT_HEADERS_DIR
	${spdlog_SOURCE_DIR}/include
)

set(PLATFORM_SRCS)

if(WIN32)
	list(APPEND PLATFORM_SRCS
		src/platform/os/windows/*.hpp
		src/platform/os/windows/*.cpp
	)
endif()

if(${WSI_TYPE} STREQUAL "SDL2")
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
	add_definitions(-DPRIMALDAWN_WSI_TYPE_SDL2)
elseif(${WSI_TYPE} STREQUAL "GLFW3")
	FetchContent_MakeAvailable(glfw3)
	list(APPEND EXTERNALS
		glfw
	)
	list(APPEND EXT_HEADERS_DIR
		${glfw3_SOURCE_DIR}/include
	)
	list(APPEND PLATFORM_SRCS
		src/platform/ws/glfw3/*.hpp
		src/platform/ws/glfw3/*.cpp
	)
	add_definitions(-DPRIMALDAWN_WSI_TYPE_GLFW)
endif()

if(${BACKEND_TYPE} STREQUAL "VULKAN")
	find_package(Vulkan REQUIRED glslc glslangValidator glslang SPIRV-Tools)
	if(NOT Vulkan_FOUND)
		message(FATAL_ERROR "Vulkan Not Found! Project build terminated")
	endif()
	FetchContent_MakeAvailable(glslang)
	list(APPEND EXTERNALS
		${Vulkan_LIBRARIES}
		glslang
		glslang-default-resource-limits
		SPIRV
		${Vulkan_SPIRV-Tools_LIBRARY}
	)
	list(APPEND EXT_HEADERS_DIR
		${Vulkan_INCLUDE_DIRS}
		${glslang_SOURCE_DIR}
	)
   add_definitions(-DPRIMALDAWN_DRIVER_SUPPORTS_VULKAN)
   	list(APPEND PLATFORM_SRCS
		src/platform/rs/vulkan/*.hpp
		src/platform/rs/vulkan/*.cpp
	)
elseif(${BACKEND_TYPE} STREQUAL "OPENGL")
	find_package(OpenGL REQUIRED OpenGL)
	if(NOT OPENGL_FOUND)
		message(FATAL_ERROR "OpenGL Not Found! Project build terminated")
	endif()
	# FIXME: cannot use fetchcontent to include library correctly
	#FetchContent_MakeAvailable(glad)
	list(APPEND EXTERNALS
		${OPENGL_LIBRARIES}
		glad
	)
	list(APPEND EXT_HEADERS_DIR
		#${OPENGL_INCLUDE_DIR}
		${glad_INCLUDE_DIR}
	)
	list(APPEND PLATFORM_SRCS
		src/platform/rs/opengl/*.hpp
		src/platform/rs/opengl/*.cpp
	)
	add_definitions(-DPRIMALDAWN_DRIVER_SUPPORTS_OPENGL)
	
endif()

set(SRC_FILES
	${ENGINE_HEADERS}
	${PLATFORM_SRCS}
	src/core/*.cpp
	src/platform/*.cpp
)

# note: not GLOB_RECURSE
file(GLOB engine_core_srcs CONFIGURE_DEPENDS ${SRC_FILES})

add_library(${TARGET} STATIC ${engine_core_srcs})

target_link_libraries(${TARGET} PUBLIC ${EXTERNALS})

target_include_directories(${TARGET} PUBLIC include src ${EXT_HEADERS_DIR})
