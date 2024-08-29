#pragma once

// internal
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <unordered_map>

// 3rd party
#include <glm/glm.hpp>

// this project

namespace PrimalDawn {
    constexpr float M_PI = 3.14159265358979323846f;

    class AbstractObject;
    class Camera;
    class Engine;
    class Entity;
    class EntityPart;
    class Light;
    class Material;
    class Mesh;
    class Meshpart;
    class Node;
    class Viewport;
    class RenderMethod;
    class RenderMethodPass;
    class Scene;
    class SceneManager;
    class SceneNode;
    class ShaderProgram;
    class TextureUnit;
    class VertexData;
    class VertexDataBuilder;


    typedef std::string String;
}