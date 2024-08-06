#include "GL4_render_system.hpp"
#include "GL4_window.hpp"

namespace PrimalDawn {
    GL4RenderSystem::GL4RenderSystem() {
        GL4Window* window = new GL4Window();
        GLFWWIndowCreateInfo createInfo;
        window->initialize(createInfo);
    }

    GL4RenderSystem::~GL4RenderSystem() {

    }

    void  GL4RenderSystem::shutdown() {

    }
}