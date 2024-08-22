#pragma once

#include "prequisites.hpp"

namespace PrimalDawn {

    class EntityFactory {
    public:
        static Entity* createPrimitive(enum ENTITY_TYPE entityType);
    };
}