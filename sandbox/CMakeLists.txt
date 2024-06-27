add_executable(sandbox)
aux_source_directory(./ SANDBOX_SRC)
target_sources(sandbox PRIVATE ${SANDBOX_SRC})
# 添加 SDL2 的头文件目录
target_link_libraries(sandbox PUBLIC PrimalDawnEngine SDL2)
CopyDLL(sandbox)