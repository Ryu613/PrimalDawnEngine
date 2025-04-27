#include "impl/renderer.hpp"

#include "primaldawn/logging.hpp"

namespace primaldawn {
    PdRenderer::PdRenderer(const PdEngine& engine)
      : engine_(engine) {

    }

    PdRenderer::~PdRenderer() noexcept {
        LOGI("destroying renderer...")
    }

    void PdRenderer::render() {

    }
} // namespace primaldawn
