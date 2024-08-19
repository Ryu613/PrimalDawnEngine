#include "GL4_plugin.hpp"

namespace PrimalDawn {
    GL4Plugin::GL4Plugin() {}

    void GL4Plugin::install() {
        renderSystem.reset(new GL4RenderSystem());
        Engine::getSingleton().setRenderSystem(renderSystem.get());
    }

    void GL4Plugin::init() {}

    void GL4Plugin::shutdown() {}

    void GL4Plugin::uninstall() {}
}