include(FetchContent)

FetchContent_Declare(
	fmt
	GIT_REPOSITORY https://github.com/fmtlib/fmt.git
	GIT_TAG 123913715afeb8a437e6388b4473fcc4753e1c9a #11.1.4
	GIT_SHALLOW TRUE
	SOURCE_DIR ${PRIMALDAWN_DIR}/externals/fmt
)
FetchContent_MakeAvailable(fmt)

set(SPDLOG_FMT_EXTERNAL ON CACHE BOOL "Use external fmt library")
FetchContent_Declare(
	spdlog
	GIT_REPOSITORY https://github.com/gabime/spdlog.git
	GIT_TAG f355b3d58f7067eee1706ff3c801c2361011f3d5 #v1.15.1
	GIT_SHALLOW TRUE
	SOURCE_DIR ${PRIMALDAWN_DIR}/externals/spdlog
)
FetchContent_MakeAvailable(spdlog)

#set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "" FORCE)
add_compile_definitions(
	BUILD_SHARED_LIBS=OFF
)
FetchContent_Declare(
	glm
	GIT_REPOSITORY https://github.com/g-truc/glm.git
	GIT_TAG 0af55ccecd98d4e5a8d1fad7de25ba429d60e863 #1.0.1
	GIT_SHALLOW TRUE
	SOURCE_DIR ${PRIMALDAWN_DIR}/externals/glm
)
FetchContent_MakeAvailable(glm)

if(NOT DEFINED WSI_TYPE OR NOT DEFINED BACKEND_TYPE)
	message(FATAL_ERROR "build fail, WSI or BACKEND not defined!")
endif()

if(${WSI_TYPE} STREQUAL "SDL2")
		add_compile_definitions(
			GLM_BUILD_TESTS=OFF
			BUILD_SHARED_LIBS=OFF
		)
	#set(GLM_BUILD_TESTS OFF CACHE INTERNAL "" FORCE)
	#set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "" FORCE)
	FetchContent_Declare(
		sdl2
		GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
		GIT_TAG e11183ea6caa3ae4895f4bc54cad2bbb0e365417 #release-2.32.2
		GIT_SHALLOW TRUE
		SOURCE_DIR ${PRIMALDAWN_DIR}/externals/sdl2
	)
elseif(${WSI_TYPE} STREQUAL "GLFW3")
	FetchContent_Declare(
		glfw3
		GIT_REPOSITORY https://github.com/glfw/glfw.git
		GIT_TAG 7b6aead9fb88b3623e3b3725ebb42670cbe4c579 #3.4
		GIT_SHALLOW TRUE
		SOURCE_DIR ${PRIMALDAWN_DIR}/externals/glfw3
		CMAKE_ARGS
			-DGLFW_BUILD_EXAMPLES=OFF
			-DGLFW_BUILD_TESTS=OFF
			-DGLFW_BUILD_DOCS=OFF
	)
endif()

if(${BACKEND_TYPE} STREQUAL "VULKAN")
	# glslang
	add_compile_definitions(
		ENABLE_SPVREMAPPER=OFF
		ENABLE_GLSLANG_BINARIES=OFF
		ENABLE_HLSL=ON
		ENABLE_OPT=OFF
		BUILD_TESTING=OFF
		BUILD_EXTERNAL=OFF
	)
	#set(ENABLE_SPVREMAPPER OFF CACHE INTERNAL "" FORCE)
	#set(ENABLE_GLSLANG_BINARIES OFF CACHE INTERNAL "" FORCE)
	#set(ENABLE_HLSL ON CACHE INTERNAL "" FORCE)
	#set(ENABLE_OPT OFF CACHE INTERNAL "" FORCE)
	#set(BUILD_TESTING OFF CACHE INTERNAL "" FORCE)
	#set(BUILD_EXTERNAL OFF CACHE INTERNAL "" FORCE)
	#if(IOS)
#		set(ENABLE_PCH OFF CACHE INTERNAL "" FORCE)
#	endif ()
	FetchContent_Declare(
		glslang
		GIT_REPOSITORY https://github.com/KhronosGroup/glslang.git
		GIT_TAG d1517d64cfca91f573af1bf7341dc3a5113349c0 #sdk-1.3.250.0
		GIT_SHALLOW TRUE
		SOURCE_DIR ${PRIMALDAWN_DIR}/externals/glslang

	)
elseif(${BACKEND_TYPE} STREQUAL "OPENGL")
	#set(GLAD_OUT_DIR "${EXTERNALS_DIR}/glad" CACHE STRING "Output directory")
    #set(GLAD_PROFILE "core" CACHE STRING "OpenGL profile" FORCE)
    #set(GLAD_API "gl=3.3" CACHE STRING "API type/version pairs, like \"gl=3.2,gles=\", no version means latest" FORCE)
    #set(GLAD_GENERATOR "c" CACHE STRING "Language to generate the binding for" FORCE)
	#set(GLAD_REPRODUCIBLE ON CACHE BOOL "" FORCE)
	#FetchContent_Declare(
	#	glad
	#	GIT_REPOSITORY https://github.com/Dav1dde/glad.git
	#	GIT_TAG 1ecd45775d96f35170458e6b148eb0708967e402 #v0.1.36
	#	GIT_SHALLOW TRUE
	#	SOURCE_DIR ${PRIMALDAWN_DIR}/externals/glad
	#)
	add_library(glad STATIC ${EXTERNALS_DIR}/glad-api3_3-no_ext/src/glad.c)
	target_include_directories(glad PUBLIC ${EXTERNALS_DIR}/glad-api3_3-no_ext/include)
endif()


