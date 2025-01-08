cmake_minimum_required(VERSION 3.27)

project(engine LANGUAGES CXX)

set(TARGET engine)
# 头文件目录
set(HEADER_DIR include)

# 头文件
set(HEADERS 
	include/core/Engine.h
	include/core/util/Logging.h
	include/platform/WindowSystem.h
	include/platform/WindowSystemSDL.h
	include/platform/PlatformEnums.h
	include/platform/PlatformFactory.h

)
# 源代码
set(SRCS
	src/Engine.cpp
	src/Logging.cpp
	src/PlatformFactory.cpp
	src/WindowSystem.cpp
	src/WindowSystemSDL.cpp
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
   list(APPEND HEADERS
     include/platform/PlatformVulkanWin32.h
   )
   list(APPEND SRCS
		src/vulkan/platform/PlatformVulkanWin32.cpp
		src/vulkan/VulkanInstance.h
		src/vulkan/VulkanInstance.cpp
   )
   add_definitions(-DPRIMALDAWN_DRIVER_SUPPORTS_VULKAN)
endif()

include_directories(${HEADER_DIR})

add_library(${TARGET} STATIC ${HEADERS} ${SRCS})

target_link_libraries(${TARGET} PUBLIC ${LIBS})

target_include_directories(${TARGET} PUBLIC ${HEADER_DIR})
