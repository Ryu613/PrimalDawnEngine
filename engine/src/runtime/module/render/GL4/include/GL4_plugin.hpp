#pragma once
#include "plugin.hpp"
#include "GL4_render_system.hpp"
#include "engine.hpp"

namespace PrimalDawn {
    class GL4Plugin : public Plugin {
        GL4RenderSystem* renderSystem;
    public:
        GL4Plugin();

        void install() override;

        void init() override;

        void shutdown() override;

        void uninstall() override;
    };
}