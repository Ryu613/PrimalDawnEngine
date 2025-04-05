#include "BoxesRenderer.hpp"
#include "core/Logging.hpp"
#include "util/Util.hpp"
#include "GLFW/glfw3.h"
#include "platform/WindowSystem.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace pd {
   void BoxesRenderer::renderBoxes(WindowSystem* windowSystem) {
       // for temporary test
       const auto assetsPath = std::filesystem::current_path() / "assets";
       const auto shaderPath = assetsPath / "shaders" / "boxes";
       const auto vertexShaderPath = shaderPath / "boxes.vert";
       const auto fragShaderPath = shaderPath / "boxes.frag";
       GLShader shader = GLShader(vertexShaderPath.string().c_str(), fragShaderPath.string().c_str());
       // cube
       float vertices[] = {
           -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
           -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
           -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

           -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
           -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
           -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

           -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
           -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
           -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
           -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
           -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
           -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

           -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
            0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
           -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
           -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

           -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
           -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
           -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
       };
       glm::vec3 cubePositions[] = {
            glm::vec3(0.0f,  0.0f,  0.0f),
            glm::vec3(2.0f,  5.0f, -15.0f),
            glm::vec3(-1.5f, -2.2f, -2.5f),
            glm::vec3(-3.8f, -2.0f, -12.3f),
            glm::vec3(2.4f, -0.4f, -3.5f),
            glm::vec3(-1.7f,  3.0f, -7.5f),
            glm::vec3(1.3f, -2.0f, -2.5f),
            glm::vec3(1.5f,  2.0f, -2.5f),
            glm::vec3(1.5f,  0.2f, -1.5f),
            glm::vec3(-1.3f,  1.0f, -1.5f)
       };
       unsigned int mVBO,mVAO;
       glGenBuffers(1, &mVBO);
       glGenVertexArrays(1, &mVAO);
       glBindVertexArray(mVAO);
       glBindBuffer(GL_ARRAY_BUFFER, mVBO);
       glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

       glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
       glEnableVertexAttribArray(0);
       glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
       glEnableVertexAttribArray(1);

       // load texture
       unsigned int mTexture1;
       glGenTextures(1, &mTexture1);
       glBindTexture(GL_TEXTURE_2D, mTexture1);
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
       int width, height, nrChannels;
       const auto texture1Path = assetsPath / "textures" / "container.jpg";
       const auto texture2Path = assetsPath / "textures" / "awesomeface.png";
       stbi_set_flip_vertically_on_load(true);
       unsigned char* data1 = stbi_load(texture1Path.string().c_str(), &width, &height, &nrChannels, 0);
       glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data1);
       glGenerateMipmap(GL_TEXTURE_2D);

       stbi_image_free(data1);

       unsigned int mTexture2;
       glGenTextures(1, &mTexture2);
       glBindTexture(GL_TEXTURE_2D, mTexture2);
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
       // set texture filtering parameters
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
       unsigned char* data2 = stbi_load(texture2Path.string().c_str(), &width, &height, &nrChannels, 0);
       glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data2);
       glGenerateMipmap(GL_TEXTURE_2D);
       stbi_image_free(data2);

       shader.use();

       glUniform1i(glGetUniformLocation(shader.ID, "texture1"), 0);
       shader.setInt("texture2", 1);

       glEnable(GL_DEPTH_TEST);
       // set matrix
       glm::mat4 view = glm::mat4(1.0f);
       glm::mat4 projection = glm::mat4(1.0f);
       // 垂直视场角， 宽高比，近平面，远平面
       projection = glm::perspective(
           glm::radians(45.0f),
           (float)(windowSystem->getExtent().width / windowSystem->getExtent().height),
           0.1f,
           100.0f);
       // 相机位置，目标位置，世界的上方向
       glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
       glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
       glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
       bool firstMouse = true;
       float yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
       float pitch = 0.0f;
       float lastX = 1024.0f / 2.0;
       float lastY = 768.0 / 2.0;
       float fov = 45.0f;
       shader.setMat4("projection", projection);
       // render loop
       float deltaTime = 0.0f;	// Time between current frame and last frame
       float lastFrame = glfwGetTime();
       GLFWwindow* window = (GLFWwindow*)windowSystem->getWindow();
       glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
       while (!windowSystem->shouldClose()) {
           float currentFrame = glfwGetTime();
           deltaTime = currentFrame - lastFrame;
           if (deltaTime < 1.0f / 60.f) {
               continue;
           }
           else {
               lastFrame = currentFrame;
           }
           windowSystem->processInput();
           float cameraSpeed = 2.5f * deltaTime;
           if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
               cameraPos += cameraSpeed * cameraFront;
           if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
               cameraPos -= cameraSpeed * cameraFront;
           if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
               cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
           if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
               cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
           glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
           glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
           glActiveTexture(GL_TEXTURE0);
           glBindTexture(GL_TEXTURE_2D, mTexture1);
           glActiveTexture(GL_TEXTURE1);
           glBindTexture(GL_TEXTURE_2D, mTexture2);
           view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
           shader.setMat4("view", view);
           glBindVertexArray(mVAO);
           for (unsigned int i = 0; i < 10; i++)
           {
               glm::mat4 model = glm::mat4(1.0f);
               model = glm::translate(model, cubePositions[i]);
               float angle = 20.0f * i;
               model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
              
               shader.setMat4("model", model);
               glDrawArrays(GL_TRIANGLES, 0, 36);
           }
           //glDrawArrays(GL_TRIANGLES, 0, 36);

           windowSystem->doEvents();
       }


       glDeleteVertexArrays(1, &mVAO);
       glDeleteBuffers(1, &mVBO);
       glDeleteProgram(shader.ID);
   }
}
