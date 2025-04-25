#include "impl/renderer.hpp"

#include "impl/logging.hpp"

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
