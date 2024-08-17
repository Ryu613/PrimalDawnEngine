#pragma once

namespace PrimalDawn {
    // 支持的着色器类型
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