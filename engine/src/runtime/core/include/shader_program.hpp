#pragma once

#include "resource.hpp" 

namespace PrimalDawn {
    // ֧�ֵ���ɫ������
    enum ShaderProgramType : uint8_t {
        VERTEX_PROGRAM = 0,
        FRAGMENT_PROGRAM,
        GEOMETRY_PROGRAM,
        COMPUTE_PROGRAM
    };
    enum {
        SHADER_COUNT = COMPUTE_PROGRAM + 1
    };
    class ShaderProgram : public Resource {

    };
}