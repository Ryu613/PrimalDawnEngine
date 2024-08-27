#pragma once
#include<map>
#include "viewport.hpp"

namespace PrimalDawn {
    typedef std::map<int, Viewport*> ViewportList;
    class RenderTarget {
    public:
        virtual void update(bool swapBuffers = true);
        virtual void swapBuffers() {}
        virtual void _updateViewport(Viewport* viewport);
        virtual void _updateAutoUpdatedViewports();
    protected:
        ViewportList mViewportList;
        // update的内部实现
        virtual void updateImpl();
    };
}