include(FetchContent)

FetchContent_Declare(
	mimalloc
	GIT_REPOSITORY https://github.com/microsoft/mimalloc.git
	GIT_TAG 94036de6fe20bfd8a73d4a6d142fcf532ea604d9 #v2.2.3
	GIT_SHALLOW TRUE
	GIT_PROGRESS TRUE
	SOURCE_DIR ${PRIMALDAWN_DIR}/externals/mimalloc
)
FetchContent_MakeAvailable(mimalloc)
