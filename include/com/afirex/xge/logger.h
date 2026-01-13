//
// Created by afirex on 1/13/26.
//

#ifndef X_GAME_ENGINE_LOGGER_H
#define X_GAME_ENGINE_LOGGER_H

#include <string>
#include <ctime>
using namespace std;

inline time_t tt;
inline tm* ti;

inline void LOG(const char* sender, const char* message) {
    time(&tt);
    ti = localtime(&tt);

    string time = asctime(ti);
    time.pop_back();

    cout << "[" << time << "] <" << sender << "> " << message << endl;
}

#endif