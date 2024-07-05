include(${PROJECT_SOURCE_DIR}/cmake/FindSDL2.cmake)

add_executable(sandbox)

# 添加 SDL2 的头文件目录
target_link_libraries(sandbox PUBLIC PrimalDawnEngine SDL2)
CopyDLL(sandbox)