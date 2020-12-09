#include "logger.h"

namespace utils {
    logger logger::instance;

    auto logger::getInstance() -> logger& {
        return instance;
    }

    void logger::toggleDebugMessages(bool show) {
        showDebug_ = show;
    }

    void logger::error(const std::string &message) const {
        if (showDebug_) {
            std::cerr << "[ERROR] >> " << message << std::endl;
        }
    }

    void logger::debug(const std::string &message) const {
        if (showDebug_) {
            std::cout << "[DEBUG] >> " << message << std::endl;
        }
    }

    void logger::info(const std::string &message) const {
        std::cout << "[INFO] >> " << message << std::endl;
    }

    logger::logger() = default;
}