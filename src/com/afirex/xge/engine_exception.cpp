//
// Created by afirex on 1/14/26.
//

#include "xge/engine_exception.h"
#include <iostream>

#include "xge/logger.h"

void ThrowException(const char *msg) {
    time_t tt = time(&tt);
    const tm* ti = localtime(&tt);

    char buffer[32];
    strftime(buffer, sizeof(buffer), "%m/%d/%Y %H:%M:%S", ti);

    std::cerr << "(" << buffer << ") <XGE-ERROR> " << msg << ", terminating..." << std::endl;
    LOG_FILE_ONLY("XGE-ERROR", (std::string(msg) + ", terminating.").c_str());
    throw std::runtime_error(msg);
}

void ThrowException(const char *msg_a, const char *msg_b) {
    time_t tt = time(&tt);
    const tm* ti = localtime(&tt);

    char buffer[32];
    strftime(buffer, sizeof(buffer), "%m/%d/%Y %H:%M:%S", ti);

    std::cerr << "(" << buffer << ") <XGE-ERROR> " << msg_a << " " << msg_b << ", terminating." << std::endl;
    LOG_FILE_ONLY("XGE-ERROR",
        (std::string(msg_a) + " " + std::string(msg_b) + ", terminating.").c_str());
    throw std::runtime_error(std::string(msg_a) + " " + msg_b);
    //TODO: Add stack traces
}
