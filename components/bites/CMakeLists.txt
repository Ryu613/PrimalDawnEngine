file(GLOB_RECURSE bites_src CONFIGURE_DEPENDS src/*.cpp include/*.hpp)
add_library(PrimalDawnBites STATIC ${bites_src})
target_link_libraries(PrimalDawnBites PUBLIC engine_lib)
target_include_directories(PrimalDawnBites PUBLIC include)
#[[
 ¶àÐÐ×¢ÊÍ
]]