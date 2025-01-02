#include "core/util/Logging.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace pd {
    namespace logging {
        void init() {
            auto logger = spdlog::stdout_color_mt("pd");
            logger->set_pattern(LOGGER_FORMAT);
            logger->set_level(spdlog::level::trace);
            spdlog::set_default_logger(logger);
        }
    }
}