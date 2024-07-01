cmake_minimum_required(VERSION 3.20)

project(
    PrimalDawnEngine 
    LANGUAGES CXX
    DESCRIPTION "PRIMAL DAWN ENGINE initial version"
    VERSION 0.1.0
)
# 把cmake脚本包含进来
include(cmake/FindVulkan.cmake)
include(cmake/FindSDL2.cmake)
include(cmake/copydll.cmake)

# 编译着色器
find_program(GLSLC_PROGRAM glslc REQUIRED)

message(STATUS "run glslc to compile shaders ...")
execute_process(COMMAND ${GLSLC_PROGRAM} ${CMAKE_SOURCE_DIR}/shaders/shader.vert -o ${CMAKE_SOURCE_DIR}/shaders/vert.spv)
execute_process(COMMAND ${GLSLC_PROGRAM} ${CMAKE_SOURCE_DIR}/shaders/shader.frag -o ${CMAKE_SOURCE_DIR}/shaders/frag.spv)
message(STATUS "compile shader OK")

# 查找路径下的所有源文件，使用SRC变量表示
aux_source_directory(src SRC)

add_library(PrimalDawnEngine STATIC ${SRC})
target_include_directories(PrimalDawnEngine PUBLIC .)
target_link_libraries(PrimalDawnEngine PUBLIC Vulkan::Vulkan)
target_compile_features(PrimalDawnEngine PUBLIC cxx_std_17)

add_subdirectory(sandbox)