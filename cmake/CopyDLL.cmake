if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
  set(SDL2_DLL "${PRIMALDAWN}/3rd_party/sdl2/lib/x64/SDL2.dll")
else ()
  set(SDL2_DLL "${PRIMALDAWN}/3rd_party/sdl2/lib/x86/SDL2.dll")
endif ()

add_custom_command(
    TARGET hello-triangle POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL2_DLL}"            # SDL2.dll 的路径
        "$<TARGET_FILE_DIR:hello-triangle>"    # 可执行文件的目标目录
)
