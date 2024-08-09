#pragma once
#include <map>
#include "render_target.hpp"

namespace PrimalDawn {

    // �����洢�����ȼ��������ȾĿ��
    typedef std::multimap<unsigned char, RenderTarget * > RenderTargetPriorityMap;
    class RenderSystem {
    public:
        RenderSystem() {};
        virtual ~RenderSystem() {};
        virtual void shutdown() = 0;
        // �ڲ��������������������뵱ǰ��Ⱦϵͳ�󶨵���ȾĿ��
        virtual void _updateAllRenderTargets(bool swapBuffers = true);
    protected:
        RenderTargetPriorityMap mPrioritisedRenderTargets;
    };
}