//
// Created by afirex on 1/13/26.
//

#include <cstring>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <ctime>
#include <sys/resource.h>
#include <chrono>

std::ofstream logfile;
std::ofstream latestfile;

bool log_statistics = false;
long lastLog = 0;

void OPEN_LOG() {
    time_t tt = time(&tt);
    const tm* ti = localtime(&tt);

    char buffer[32];
    strftime(buffer, sizeof(buffer), "%m-%d-%Y %H:%M:%S", ti);

    if (std::filesystem::current_path().filename() == "cmake-build-debug") {
        logfile = std::ofstream(std::filesystem::current_path()
            .remove_filename()
            .concat("var/logs/")
            .concat(buffer)
            .concat(".txt"));
        latestfile = std::ofstream(std::filesystem::current_path()
            .remove_filename()
            .concat("var/logs/")
            .concat("latest.txt"));
    } else {
        logfile = std::ofstream(std::filesystem::current_path()
            .concat("var/logs/")
            .concat(buffer)
            .concat(".txt"));
        latestfile = std::ofstream(std::filesystem::current_path()
            .concat("var/logs/")
            .concat("latest.txt"));
    }

    logfile << "Execution start at: " << buffer << std::endl << std::endl;
    latestfile << "Execution start at: " << buffer << std::endl << std::endl;

    const auto now =
        std::chrono::system_clock::now();
    const auto nanoseconds =
        std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch());
    lastLog = nanoseconds.count();
}

void LOG(const char* sender, const char* message) {
    time_t tt = time(&tt);
    const tm* ti = localtime(&tt);

    char buffer[32];
    strftime(buffer, sizeof(buffer), "%m/%d/%Y %H:%M:%S", ti);

    std::cout << "[" << buffer << "] <" << sender << "> " << message << std::endl;
    logfile << "[" << buffer << "] <" << sender << "> " << message << std::endl;
    latestfile << "[" << buffer << "] <" << sender << "> " << message << std::endl;

    if (log_statistics) {
        rusage usage{};
        getrusage(RUSAGE_SELF, &usage);
        const auto now =
            std::chrono::system_clock::now();
        const auto nanoseconds =
            std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch());

        std::cout << "^(MemUsage: " << usage.ru_maxrss  << " KB), (Time since previous: "
            << (nanoseconds.count()-lastLog) << "ns, "
            << (static_cast<double>(nanoseconds.count() - lastLog)/1000000.0) << "ms)" << std::endl;
        lastLog = nanoseconds.count();
    }
}

void LOG_CONSOLE_ONLY(const char* sender, const char* message) {
    time_t tt = time(&tt);
    const tm* ti = localtime(&tt);

    char buffer[32];
    strftime(buffer, sizeof(buffer), "%m/%d/%Y %H:%M:%S", ti);

    std::cout << "[" << buffer << "] <" << sender << "> " << message << std::endl;

    if (log_statistics) {
        rusage usage{};
        getrusage(RUSAGE_SELF, &usage);
        const auto now =
            std::chrono::system_clock::now();
        const auto nanoseconds =
            std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch());

        std::cout << "^(MemUsage: " << usage.ru_maxrss  << " KB), (Time since previous: "
            << (nanoseconds.count()-lastLog) << "ns, "
            << (static_cast<double>(nanoseconds.count() - lastLog)/1000000.0) << "ms)" << std::endl;
        lastLog = nanoseconds.count();
    }
}

void LOG_FILE_ONLY(const char* sender, const char* message) {
    time_t tt = time(&tt);
    const tm* ti = localtime(&tt);

    char buffer[32];
    strftime(buffer, sizeof(buffer), "%m/%d/%Y %H:%M:%S", ti);

    logfile << "[" << buffer << "] <" << sender << "> " << message << std::endl;
    latestfile << "[" << buffer << "] <" << sender << "> " << message << std::endl;
}

void CLOSE_LOG() {
    logfile.close();
    latestfile.close();
}

void LOG_STATISTICS(const bool a) {
    log_statistics = a;
}
