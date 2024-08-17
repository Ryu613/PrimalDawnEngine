#include "render_system.hpp"

namespace PrimalDawn {
    void RenderSystem::_updateAllRenderTargets(bool swapBuffers) {
        // 根据优先级更新所有渲染目标
        for (auto& rt : mPrioritisedRenderTargets) {
            rt.second->update(swapBuffers);
        }
    }
}