#pragma once

namespace PrimalDawn {
    // ֧�ֵ���ɫ������
    enum ShaderProgramType : unit8 {
        VERTEX_PROGRAM = 0,
        FRAGMENT_PROGRAM,
        GEOMETRY_PROGRAM,
        COMPUTE_PROGRAM
    };
    enum {
        SHADER_COUNT = COMPUTE_PROGRAM + 1
    };
    class ShaderProgram {

    };
}