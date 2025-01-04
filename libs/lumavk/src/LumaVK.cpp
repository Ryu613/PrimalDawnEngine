#include "lumavk/LumaVK.h"

#include <stdexcept>

#include "volk.h"
#include "lumavk/Context.h"

namespace lumavk {
    bool init() {
        if (!volkInitialize()) {
            throw std::runtime_error("Failed to initialize volk!");
        }
        return true;
    }
}
