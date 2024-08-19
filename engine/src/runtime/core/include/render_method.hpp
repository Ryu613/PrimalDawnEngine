#pragma once
#include <vector>
#include "render_method_pass.hpp"

namespace PrimalDawn {
    class RenderMethod {
    public:
        typedef std::vector<RenderMethodPass*> renderMethodPasses;
    private:
        // 渲染方法对应的渲染流程
        renderMethodPasses mRenderMethodPasses;
    };
}