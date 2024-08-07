#file(GLOB_RECURSE core_src CONFIGURE_DEPENDS src/*.cpp include/*.hpp)
#add_library(core_lib STATIC ${core_src})
#target_include_directories(core_lib PUBLIC include)
#set_target_properties(core_lib PROPERTIES LINKER_LANGUAGE CXX)
file(GLOB_RECURSE core_src CONFIGURE_DEPENDS src/*.cpp include/*.hpp)
add_library(core_lib STATIC ${core_src})

find_package(spdlog CONFIG REQUIRED)

target_include_directories(core_lib PUBLIC include)

target_link_libraries(core_lib PUBLIC spdlog::spdlog)