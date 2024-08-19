#pragma once

#include <vector>
#include "resource.hpp"
#include "render_method.hpp"

namespace PrimalDawn {
    class Material : public Resource {
    public:
        typedef std::vector<RenderMethod*> renderMethods;
    public:
        Material();
        ~Material();
    private:
        renderMethods mRenderMethods;
    };
}