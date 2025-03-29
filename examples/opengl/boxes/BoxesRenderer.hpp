#pragma once

#include <glad/glad.h>
#include "platform/rs/opengl/RenderSystemOpenGL.hpp"
#include "platform/rs/opengl/GLShader.hpp"

#include "Boxes.hpp"


namespace pd {
    class BoxesRenderer {
    public:
        BoxesRenderer() = default;
        void renderBoxes(WindowSystem* windowSystem);
    };
}
