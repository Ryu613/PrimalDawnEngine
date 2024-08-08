#include "GL4_render_system.hpp"
#include "GL4_window.hpp"

namespace PrimalDawn {
    GL4RenderSystem::GL4RenderSystem() {
        _window.reset(new GL4Window());
        GLFWWIndowCreateInfo createInfo;
        _window->initialize(createInfo);
    }

    GL4RenderSystem::~GL4RenderSystem() {
        
    }

    void  GL4RenderSystem::shutdown() {

    }
}