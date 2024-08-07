file(GLOB_RECURSE render_gl4_src CONFIGURE_DEPENDS src/*.cpp include/*.hpp)
add_library(render_gl4 STATIC ${render_gl4_src})
target_include_directories(render_gl4 PUBLIC include)

include(${PROJECT_SOURCE_DIR}/cmake/FindGLFW3.cmake)

target_link_libraries(render_gl4 PUBLIC core_lib glfw)