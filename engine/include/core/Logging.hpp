#pragma once

#ifndef SPDLOG_FMT_EXTERNAL
#define SPDLOG_FMT_EXTERNAL
#endif

#include "spdlog/fmt/fmt.h"
#include "spdlog/spdlog.h"

#define LOGGER_FORMAT "[%^%l%$] %v"
#define PROJECT_NAME "PrimalDawnEngine"

#define LOG_INFO(...) spdlog::info(__VA_ARGS__);
#define LOG_WARN(...) spdlog::warn(__VA_ARGS__);
#define LOG_ERROR(...) spdlog::error("{}", fmt::format(__VA_ARGS__));
#define LOG_DEBUG(...) spdlog::debug(__VA_ARGS__);

namespace pd {
    namespace logging {
        void init();
    }
}
