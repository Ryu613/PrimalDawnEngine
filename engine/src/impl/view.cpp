#include "impl/view.hpp"

#include "impl/engine.hpp"
#include "impl/scene.hpp"
#include "impl/camera.hpp"

namespace primaldawn {
    PdView::PdView(const PdEngine& engine)
      : engine_(engine) {

    }

    PdView::~PdView() noexcept {

    }
} // namespace primaldawn
