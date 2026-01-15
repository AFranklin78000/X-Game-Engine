//
// Created by afirex on 1/14/26.
//

#ifndef X_GAME_ENGINE_PLATFORM_H
#define X_GAME_ENGINE_PLATFORM_H

#include <SDL3/SDL.h>

struct Platform {
    SDL_Window* window = nullptr;
    bool running = true;
};

#endif