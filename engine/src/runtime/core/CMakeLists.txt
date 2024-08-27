file(GLOB_RECURSE core_src CONFIGURE_DEPENDS src/*.cpp include/*.hpp)
add_library(core_lib STATIC ${core_src})

include(${PROJECT_SOURCE_DIR}/cmake/Find3rdParty.cmake)

target_include_directories(core_lib PUBLIC include)

target_link_libraries(core_lib PUBLIC spdlog::spdlog glm::glm Boost::json Boost::fusion)