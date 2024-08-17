#pragma once
#include <vector>
#include "render_method_pass.hpp"

namespace PrimalDawn {
    class RenderMethod {
    public:
        typedef std::vector<RenderMethodPass*> renderMethodPasses;
    private:
        renderMethodPasses mRenderMethodPasses;
    };
}