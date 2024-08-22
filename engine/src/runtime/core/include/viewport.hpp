#pragma once

#include "prequisites.hpp"

namespace PrimalDawn {
    class Viewport {
    public:
        void update();
    private:
        Camera* mCamera;
    };
}