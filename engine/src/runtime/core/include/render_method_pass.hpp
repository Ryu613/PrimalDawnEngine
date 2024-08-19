#pragma once

#include <memory>
#include "color_value.hpp"
#include "texture_unit.hpp"
#include "shader_program.hpp"

namespace PrimalDawn {

    class RenderMethodPass {
    public:
        typedef std::vector<TextureUnit*> TextureUnitList;
    private:
        ColorValue mAmbient;
        ColorValue mDiffuse;
        ColorValue mSpecular;
        TextureUnitList mTextureObjects;
        std::unique_ptr<ShaderProgram> mShaderProgram[SHADER_COUNT]
    };
}