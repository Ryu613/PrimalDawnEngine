#version 450

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform mat4 model;

void main() {
    gl_Position = model * vec4(aPos, 1.0);
    TexCoord = aTexCoord;
}
