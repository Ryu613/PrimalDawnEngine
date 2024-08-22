#pragma once

#include "prequisites.hpp"
#include "abstract_object.hpp"

namespace PrimalDawn {
    class Camera : public AbstractObject {
    public:
        Camera();
        ~Camera();
        Camera(const String& name, Scene* scene);
        void _renderScene(Viewport* vp);
    protected:
        Scene* mScene;
    private:
        float mPixelDisplayRatio;
    };
} 