#pragma once

#ifndef SPDLOG_FMT_EXTERNAL
#define SPDLOG_FMT_EXTERNAL
#endif

#include "spdlog/fmt/fmt.h"
#include "spdlog/spdlog.h"

#define LOGGER_FORMAT "[%^%l%$] %v"
#define PROJECT_NAME "PrimalDawnEngine"

#define LOGI(...) spdlog::info(__VA_ARGS__);
#define LOGW(...) spdlog::warn(__VA_ARGS__);
#define LOGE(...) spdlog::error("{}", fmt::format(__VA_ARGS__));
#define LOGD(...) spdlog::debug(__VA_ARGS__);

namespace pd {
    namespace logging {
        void init();
    }
}
