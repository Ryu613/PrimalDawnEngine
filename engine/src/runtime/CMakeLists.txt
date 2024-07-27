add_subdirectory(module/render)

file(GLOB_RECURSE engine_src CONFIGURE_DEPENDS *.cpp *.hpp)
add_library(engine_lib STATIC ${engine_src})
target_include_directories(engine_lib PUBLIC .)
target_link_libraries(engine_lib PRIVATE render_vulkan)
