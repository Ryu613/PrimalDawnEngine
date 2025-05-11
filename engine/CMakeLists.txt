cmake_minimum_required(VERSION 3.27)

project(engine LANGUAGES CXX)

set(TARGET engine)

# 第三方库依赖
include(${PRIMALDAWN_DIR}/cmake/externals-core.cmake)

set(ENGINE_PUBLIC_HEADERS
	include/primaldawn/*.hpp
)

set(ENGINE_PRIVATE_HEADERS
	src/*.hpp
	src/impl/*.hpp
)

set(EXTERNALS
	primaldawn_utils
	fmt
	spdlog::spdlog
	glm
)

set(EXT_HEADERS_DIR
	${spdlog_SOURCE_DIR}/include
	${EXTERNALS_DIR}/stb/include
)

set(PLATFORM_SRCS)

if(WIN32)
	list(APPEND PLATFORM_SRCS
		src/platform/os/platform_windows.hpp
		src/platform/os/platform_windows.cpp
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
		src/platform/window_system/window_system_sdl2.hpp
		src/platform/window_system/window_system_sdl2.cpp
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
		src/platform/window_system/window_system_glfw3.hpp
		src/platform/window_system/window_system_glfw3.cpp
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
		src/platform/render_system/render_system_vulkan.hpp
		src/platform/render_system/render_system_vulkan.cpp
		src/platform/render_system/vulkan/*.hpp
		src/platform/render_system/vulkan/*.cpp
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
		src/platform/render_system/render_system_opengl.hpp
		src/platform/render_system/render_system_opengl.cpp
	)
	add_definitions(-DPRIMALDAWN_DRIVER_SUPPORTS_OPENGL)
	
endif()

set(SRC_FILES
	${ENGINE_PUBLIC_HEADERS}
	${ENGINE_PRIVATE_HEADERS}
	${PLATFORM_SRCS}
	src/*.cpp
	src/utils/*.cpp
	src/impl/*.cpp
	src/impl/utils/*.cpp
)

# note: not GLOB_RECURSE
file(GLOB engine_srcs CONFIGURE_DEPENDS ${SRC_FILES})

add_library(${TARGET} STATIC ${engine_srcs})

# here is local include
include_directories(include src)

target_link_libraries(${TARGET} PUBLIC ${EXTERNALS})

# here is library include
target_include_directories(${TARGET} PUBLIC include ${EXT_HEADERS_DIR})
