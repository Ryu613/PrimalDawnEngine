#include "RenderSystemOpenGL.hpp"
#include "core/SwapChain.hpp"
#include "core/Logging.hpp"

namespace pd {
    RenderSystemOpenGL::RenderSystemOpenGL(OpenGLConfig& config)
        : RenderSystem(config),
        mOpenGLConfig(config) {
    }

    RenderSystemOpenGL::~RenderSystemOpenGL() {
        //TODO destroy
    };

    std::unique_ptr<SwapChain> RenderSystemOpenGL::createSwapChain(Engine& engine, WindowSystem* windowSystem) {
        return nullptr;
    }
    void RenderSystemOpenGL::bindPipeline(const PipelineDesc& pipelineDesc) {
    }
    void RenderSystemOpenGL::draw(PipelineDesc desc) {
        // FIXME: render command, place here for temporary
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(mShaderProgram);
        glBindVertexArray(mVAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    void RenderSystemOpenGL::beginRenderPass() {
        // for temporary test
        const char* vertexShaderSource = "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            "}\0";
        unsigned int vertexShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            LOG_ERROR("SHADER::VERTEX::COMPILATION_FAILED: {}", infoLog)
                return;
        }

        const char* fragmentShaderSource = "#version 330 core\n"
            "out vec4 FragColor;\n"
            "void main()\n"
            "{\n"
            "FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
            "}\n\0 ";
        unsigned int fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            LOG_ERROR("SHADER::VERTEX::COMPILATION_FAILED: {}", infoLog)
                return;
        }
        mShaderProgram = glCreateProgram();

        glAttachShader(mShaderProgram, vertexShader);
        glAttachShader(mShaderProgram, fragmentShader);
        glLinkProgram(mShaderProgram);

        glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(mShaderProgram, 512, NULL, infoLog);
            LOG_ERROR("SHADER::VERTEX::PROGRAM::LINKING_FAILED: {}", infoLog)
            return;
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        float vertices[] = {
       -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
        };
        glGenBuffers(1, &mVBO);
        glGenVertexArrays(1, &mVAO);
        glBindVertexArray(mVAO);
        glBindBuffer(GL_ARRAY_BUFFER, mVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // note that this is allowed, the call to glVertexAttribPointer registered VBO
        // as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
        // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
        glBindVertexArray(0);

    }
    void RenderSystemOpenGL::endRenderPass() {
        glDeleteVertexArrays(1, &mVAO);
        glDeleteBuffers(1, &mVBO);
        glDeleteProgram(mShaderProgram);
    }

    void RenderSystemOpenGL::prepare() {

    }
}
