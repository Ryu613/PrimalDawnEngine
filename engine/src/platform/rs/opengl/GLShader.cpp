#include "GLShader.hpp"
#include "util/Util.hpp"
#include "core/Logging.hpp"

namespace pd {
    GLShader::GLShader(const char* vertexPath, const char* fragmentPath) {
        std::vector<char> vertCode = util::readFile(vertexPath);
        std::vector<char> fragCode = util::readFile(fragmentPath);
        const char* vCode = vertCode.data();
        const char* fCode = fragCode.data();
        unsigned int vertexShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vCode, NULL);
        glCompileShader(vertexShader);
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            LOG_ERROR("SHADER::VERTEX::COMPILATION_FAILED: {}", infoLog)
                return;
        }
        unsigned int fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fCode, NULL);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            LOG_ERROR("SHADER::VERTEX::COMPILATION_FAILED: {}", infoLog)
                return;
        }
        ID = glCreateProgram();

        glAttachShader(ID, vertexShader);
        glAttachShader(ID, fragmentShader);
        glLinkProgram(ID);

        glGetProgramiv(ID, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(ID, 512, NULL, infoLog);
            LOG_ERROR("SHADER::VERTEX::PROGRAM::LINKING_FAILED: {}", infoLog)
                return;
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    void GLShader::use() {
        glUseProgram(ID);
    }
    void GLShader::setBool(const std::string& name, bool value) const {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
    }
    void GLShader::setInt(const std::string& name, bool value) const {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
    }
    void GLShader::setFloat(const std::string& name, bool value) const {
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
    }
}
