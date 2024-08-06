#include "GL4_plugin.hpp"

namespace PrimalDawn {
    GL4Plugin::GL4Plugin() {}

    void GL4Plugin::install() {
        renderSystem = new GL4RenderSystem();
        Engine::Instance().setRenderSystem(renderSystem);
    }

    void GL4Plugin::init() {}

    void GL4Plugin::shutdown() {}

    void GL4Plugin::uninstall() {}
}