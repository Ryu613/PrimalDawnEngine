#pragma once

namespace PrimalDawn {
    class RenderSystem {
    public:
        RenderSystem() {};
        virtual ~RenderSystem() {};
        virtual void shutdown() = 0;
    };
}