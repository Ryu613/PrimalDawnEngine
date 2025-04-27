#include "impl/renderer.hpp"

#include "primaldawn/logging.hpp"
#include "impl/engine.hpp"
#include "impl/view.hpp"

namespace primaldawn {
    PdRenderer::PdRenderer(PdEngine& engine)
      : engine_(engine) {

    }

    PdRenderer::~PdRenderer() noexcept {
        LOGI("destroying renderer...")
    }

    void PdRenderer::Render(const PdView* view) {
    }
} // namespace primaldawn
