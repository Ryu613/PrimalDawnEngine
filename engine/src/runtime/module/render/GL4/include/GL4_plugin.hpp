#pragma once
#include "plugin.hpp"
#include "GL4_render_system.hpp"
#include "engine.hpp"
#include <memory>

namespace PrimalDawn {
    class GL4Plugin : public Plugin {
    public:
        GL4Plugin();

        void install() override;

        void init() override;

        void shutdown() override;

        void uninstall() override;
    protected:
        std::unique_ptr<GL4RenderSystem> renderSystem;
    };
}