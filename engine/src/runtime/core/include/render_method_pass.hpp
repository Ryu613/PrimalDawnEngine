#pragma once

#include <memory>
#include "color_value.hpp"
#include "texture_object.hpp"
#include "shader_program.hpp"

namespace PrimalDawn {

    class RenderMethodPass {
    public:
        typedef std::vector<TextureObject*> textureObjects;
    private:
        ColorValue mAmbient;
        ColorValue mDiffuse;
        ColorValue mSpecular;
        textureObjects mTextureObjects;
        std::unique_ptr<ShaderProgram> mShaderProgram[SHADER_COUNT]
    };
}