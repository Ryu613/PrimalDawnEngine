cmake_minimum_required(VERSION 3.27)

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
	include/platform/DriverEnums.h
	include/platform/PlatformFactory.h
	include/platform/Driver.h

)
# 源代码
set(SRCS
	src/Engine.cpp
	src/Window.cpp
	src/Logging.cpp
	src/SDLWindow.cpp
	src/PlatformFactory.cpp
)

set(LIBS
	spdlog::spdlog
	sdl2
)

if(SUPPORT_VULKAN)
	find_package(Vulkan REQUIRED)
	if(NOT Vulkan_FOUND)
		message(FATAL_ERROR "Vulkan Not Found! Project build terminated")
	endif()
   list(APPEND LIBS
	 ${Vulkan_LIBRARIES}
   )
   list(APPEND HEADER_DIR
	 ${Vulkan_INCLUDE_DIR}
   )
   list(APPEND SRCS
		src/vulkan/platform/PlatformVulkan.cpp
		src/vulkan/VulkanInstance.h
		src/vulkan/VulkanInstance.cpp
   )
   add_definitions(-DPRIMALDAWN_DRIVER_SUPPORTS_VULKAN)
endif()

include_directories(${HEADER_DIR})

add_library(${TARGET} STATIC ${HEADERS} ${SRCS})

target_link_libraries(${TARGET} PUBLIC ${LIBS})

target_include_directories(${TARGET} PUBLIC ${HEADER_DIR})
