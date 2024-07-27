# ‘› ± π”√vulkan
set(RENDERSYSTEM_VULKAN 1)
if(RENDERSYSTEM_OPENGL) 
	add_subdirectory(OpenGL)
endif()
if(RENDERSYSTEM_VULKAN)
	add_subdirectory(Vulkan)
endif()