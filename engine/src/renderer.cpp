#include "impl/renderer.hpp"

#include "impl/engine.hpp"
#include "impl/view.hpp"

namespace primaldawn {
    Engine* Renderer::GetEngine() noexcept {
        return &downcast(this)->GetEngine();
    }

    void Renderer::Render(const View* view) {
        downcast(this)->Render(downcast(view));
    }
} // namespace primaldawn
