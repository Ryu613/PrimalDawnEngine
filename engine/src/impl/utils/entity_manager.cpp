#include "impl/utils/entity_manager.hpp"

#include "impl/utils/entity.hpp"

namespace primaldawn::utils {
    PdEntityManager::PdEntityManager()
      : current_index_(1) {

    }

    void PdEntityManager::Create(int num, PdEntity* entity) {
        //TODO: support multithread index
        for (int i = 0; i < num; ++i) {
            entity[i] = PdEntity(current_index_++);
        }
    }

    void PdEntityManager::Destroy(int num, PdEntity* entity) noexcept {

    }
} // namespace primaldawn::utils
