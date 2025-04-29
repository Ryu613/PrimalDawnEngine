#include "primaldawn/utils/entity.hpp"

#include "impl/utils/entity.hpp"

#include "downcast.hpp"

namespace primaldawn::utils {
    bool Entity::operator==(Entity e) const {
        return *downcast(this) == downcast(e);
    }

    bool Entity::operator!=(Entity e) const {
        return *downcast(this) != downcast(e);
    }

    bool Entity::operator<(Entity e) const {
        return *downcast(this) < downcast(e);
    }

    bool Entity::isNull() const noexcept {
        return downcast(this)->isNull();
    }

    Entity::operator bool() const noexcept {
        return downcast(this)->operator bool();
    }

    uint32_t Entity::GetId() const noexcept {
        return downcast(this)->GetId();
    }
}
