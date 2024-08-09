#include "render_target.hpp"

namespace PrimalDawn {
    void RenderTarget::update(bool swap) {
        updateImpl();
        if (swap) {
            swapBuffers();
        }
    }

    void RenderTarget::updateImpl() {
        PrimalDawn::RenderTarget::_updateAutoUpdatedViewports();
    }

    void RenderTarget::_updateAutoUpdatedViewports() {
        for (const auto& v : mViewportList) {
            Viewport* viewport = v.second;
            _updateViewport(viewport);
        }
    }

    void RenderTarget::_updateViewport(Viewport* viewport) {
        viewport->update();
    }
}