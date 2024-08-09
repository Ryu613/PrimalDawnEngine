#pragma once
#include <memory>
#include "plugin.hpp"
#include "engine.hpp"
#include "GL4_render_system.hpp"

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