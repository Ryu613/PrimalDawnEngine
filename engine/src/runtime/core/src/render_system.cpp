#include "render_system.hpp"

namespace PrimalDawn {
    void RenderSystem::_updateAllRenderTargets(bool swapBuffers) {
        for (auto& rt : mPrioritisedRenderTargets) {
            rt.second->update(swapBuffers);
        }
    }
}