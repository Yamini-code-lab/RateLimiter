#include "logger.h"
#include <iostream>

void Logger::info(const std::string& msg) {
    std::cout << "[LOG] " << msg << std::endl;
}