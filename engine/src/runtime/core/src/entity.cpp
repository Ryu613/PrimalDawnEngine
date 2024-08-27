#include "entity.hpp"
#include "mesh.hpp"
#include "entity_part.hpp"

namespace PrimalDawn {
    Entity::Entity() {
        mEntityPartList.push_back(std::make_unique<EntityPart>());
    }

    Entity::Entity(std::shared_ptr<Mesh> mesh) {
        mMesh = mesh;
        for (const auto& eachMeshPart : mesh->getMeshPartList()) {
            std::unique_ptr<EntityPart> entityPart = std::make_unique<EntityPart>(eachMeshPart.get());
            mEntityPartList.push_back(std::move(entityPart));
        }
    }

    Entity::~Entity() {

    }
}