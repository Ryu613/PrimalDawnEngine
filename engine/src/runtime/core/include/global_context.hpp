#pragma once
#include <memory>
#include <string>

namespace PrimalDawn {
    class LogSystem;
    class RuntimeGlobalContext {
    public:
        void startSystems();
        void shutdownSystems();
    public:
        std::shared_ptr<LogSystem> g_logger_system;
    };

    extern RuntimeGlobalContext global_runtime_context;
}