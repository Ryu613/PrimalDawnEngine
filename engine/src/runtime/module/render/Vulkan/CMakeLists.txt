file(GLOB_RECURSE render_vulkan_src CONFIGURE_DEPENDS src/*.cpp include/*.hpp)
add_library(render_vulkan STATIC ${render_vulkan_src})
target_include_directories(render_vulkan PUBLIC include)

# 引入vulkan库
include(${PROJECT_SOURCE_DIR}/cmake/FindVulkan.cmake)
include(${PROJECT_SOURCE_DIR}/cmake/FindSDL2.cmake)
target_link_libraries(render_vulkan PUBLIC Vulkan::Vulkan SDL2::SDL2main)

# 编译着色器
find_program(GLSLC_PROGRAM glslc REQUIRED)

message(STATUS "run glslc to compile shaders ...")
execute_process(COMMAND ${GLSLC_PROGRAM} ${CMAKE_SOURCE_DIR}/engine/shader/shader.vert -o ${CMAKE_SOURCE_DIR}/engine/shader/vert.spv)
execute_process(COMMAND ${GLSLC_PROGRAM} ${CMAKE_SOURCE_DIR}/engine/shader/shader.frag -o ${CMAKE_SOURCE_DIR}/engine/shader/frag.spv)
message(STATUS "compile shader OK")