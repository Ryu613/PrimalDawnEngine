#pragma once
#include <map>
#include "render_target.hpp"

namespace PrimalDawn {

    // 用来存储按优先级排序的渲染目标
    typedef std::multimap<unsigned char, RenderTarget* > RenderTargetPriorityMap;
    class RenderSystem {
    public:
        RenderSystem() {};
        virtual ~RenderSystem() {};
        virtual void shutdown() = 0;
        // 内部函数，用来更新所有与当前渲染系统绑定的渲染目标
        virtual void _updateAllRenderTargets(bool swapBuffers = true);
    protected:
        RenderTargetPriorityMap mPrioritisedRenderTargets;
    };
}