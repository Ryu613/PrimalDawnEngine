#include "global_context.hpp"
#include "log_system.hpp"

namespace PrimalDawn {
    RuntimeGlobalContext global_runtime_context;

    void RuntimeGlobalContext::startSystems() {
        g_logger_system = std::make_shared<LogSystem>();
    }

    void RuntimeGlobalContext::shutdownSystems() {
        g_logger_system.reset();
    }
}