#include "impl/logging.hpp"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace primaldawn::logging {
    void Init() {
        auto logger = spdlog::stdout_color_mt("pd");
        logger->set_pattern(LOGGER_FORMAT);
        logger->set_level(spdlog::level::trace);
        spdlog::set_default_logger(logger);
    }
}
