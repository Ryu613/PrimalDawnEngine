include(FetchContent)

FetchContent_Declare(
	fmt
	GIT_REPOSITORY https://github.com/fmtlib/fmt.git
	GIT_TAG 123913715afeb8a437e6388b4473fcc4753e1c9a #11.1.4
	SOURCE_DIR ${PRIMALDAWN_DIR}/externals/fmt
)
FetchContent_MakeAvailable(fmt)

set(SPDLOG_FMT_EXTERNAL ON CACHE BOOL "Use external fmt library")
FetchContent_Declare(
	spdlog
	GIT_REPOSITORY https://github.com/gabime/spdlog.git
	GIT_TAG f355b3d58f7067eee1706ff3c801c2361011f3d5 #v1.15.1
	SOURCE_DIR ${PRIMALDAWN_DIR}/externals/spdlog
)
FetchContent_MakeAvailable(spdlog)

set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "" FORCE)
FetchContent_Declare(
	glm
	GIT_REPOSITORY https://github.com/g-truc/glm.git
	GIT_TAG 0af55ccecd98d4e5a8d1fad7de25ba429d60e863 #1.0.1
	SOURCE_DIR ${PRIMALDAWN_DIR}/externals/glm
)
FetchContent_MakeAvailable(glm)
		
set(GLM_BUILD_TESTS OFF CACHE INTERNAL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "" FORCE)
FetchContent_Declare(
	sdl2
	GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
	GIT_TAG e11183ea6caa3ae4895f4bc54cad2bbb0e365417 #release-2.32.2
	SOURCE_DIR ${PRIMALDAWN_DIR}/externals/sdl2
)
# glslang
set(ENABLE_SPVREMAPPER OFF CACHE INTERNAL "" FORCE)
set(ENABLE_GLSLANG_BINARIES OFF CACHE INTERNAL "" FORCE)
set(ENABLE_HLSL ON CACHE INTERNAL "" FORCE)
set(ENABLE_OPT OFF CACHE INTERNAL "" FORCE)
set(BUILD_TESTING OFF CACHE INTERNAL "" FORCE)
set(BUILD_EXTERNAL OFF CACHE INTERNAL "" FORCE)
if(IOS)
    set(ENABLE_PCH OFF CACHE INTERNAL "" FORCE)
endif ()
FetchContent_Declare(
	glslang
	GIT_REPOSITORY https://github.com/KhronosGroup/glslang.git
	GIT_TAG d1517d64cfca91f573af1bf7341dc3a5113349c0 #sdk-1.3.250.0
	SOURCE_DIR ${PRIMALDAWN_DIR}/externals/glslang
)

