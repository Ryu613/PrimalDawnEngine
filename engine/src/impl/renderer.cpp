#include "impl/renderer.hpp"

#include "primaldawn/logging.hpp"
#include "impl/view.hpp"

namespace primaldawn {
    PdRenderer::PdRenderer(const PdEngine& engine)
      : engine_(engine) {

    }

    PdRenderer::~PdRenderer() noexcept {
        LOGI("destroying renderer...")
    }

    void PdRenderer::Render(const PdView* view) {
    }
} // namespace primaldawn
