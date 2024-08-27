#pragma once
#include "prequisites.hpp"
#include "render_method_pass.hpp"

namespace PrimalDawn {
    class RenderMethod {
    public:
        typedef std::vector<std::unique_ptr<RenderMethodPass>> renderMethodPasses;
    private:
        // 渲染方法对应的渲染流程
        renderMethodPasses mRenderMethodPasses;
    public:
        RenderMethod();
        ~RenderMethod();
    };
}