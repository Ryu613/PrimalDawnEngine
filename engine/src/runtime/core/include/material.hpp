#pragma once

#include "prequisites.hpp"
#include "resource.hpp"
#include "render_method.hpp"

namespace PrimalDawn {
    class Material : public Resource {
    public:
        typedef std::vector<std::unique_ptr<RenderMethod>> renderMethods;
    private:
        renderMethods mRenderMethods;
    public:
        Material();
        ~Material();
        void setVertexData(VertexData& vertexData);
    };
}