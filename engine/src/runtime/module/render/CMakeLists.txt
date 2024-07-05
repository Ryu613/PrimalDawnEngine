file(GLOB_RECURSE render_src CONFIGURE_DEPENDS src/*.cpp include/*.hpp)
add_library(render STATIC ${render_src})
target_include_directories(render PUBLIC include)