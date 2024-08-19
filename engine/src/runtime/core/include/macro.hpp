#pragma once

#include "log_manager.hpp"

#define LOG_HELPER(LOG_LEVEL, ...) \
    PrimalDawn::LogManager::getSingleton().log(LOG_LEVEL, "[" + std::string(__FUNCTION__) + "] " + __VA_ARGS__);

#define LOG_DEBUG(...) LOG_HELPER(PrimalDawn::LogManager::LogLevel::debug, __VA_ARGS__);

#define LOG_INFO(...) LOG_HELPER(PrimalDawn::LogManager::LogLevel::info, __VA_ARGS__);

#define LOG_WARN(...) LOG_HELPER(PrimalDawn::LogManager::LogLevel::warn, __VA_ARGS__);

#define LOG_ERROR(...) LOG_HELPER(PrimalDawn::LogManager::LogLevel::error, __VA_ARGS__);

#define LOG_FATAL(...) LOG_HELPER(PrimalDawn::LogManager::LogLevel::fatal, __VA_ARGS__);
