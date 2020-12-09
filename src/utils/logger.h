#ifndef LINAL_EINDOPDRACHT_LOGGER_H
#define LINAL_EINDOPDRACHT_LOGGER_H

#include <iostream>

namespace utils {
    class logger {
        static logger instance;
        bool showDebug_ = false;
    public:
        static auto getInstance() -> logger&;
        void toggleDebugMessages(bool show);
        void error(const std::string& message) const;
        void debug(const std::string& message) const;
        void info(const std::string& message) const;
    private:
        logger();
    };
}


#endif //LINAL_EINDOPDRACHT_LOGGER_H
