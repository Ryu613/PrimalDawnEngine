#pragma once

#include "abstract_object.hpp"

namespace PrimalDawn {

    class EntityFactory {
    public:
        static Entity* createPrimitive(enum ENTITY_TYPE entityType);
    };
}