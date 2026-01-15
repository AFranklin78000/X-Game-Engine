//
// Created by afirex on 1/13/26.
//

#ifndef X_GAME_ENGINE_LOGGER_H
#define X_GAME_ENGINE_LOGGER_H

void OPEN_LOG();
void LOG(const char* sender, const char* message);
void CLOSE_LOG();
void LOG_STATISTICS(bool a);

#endif