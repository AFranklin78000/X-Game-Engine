//
// Created by afirex on 1/14/26.
//

#include "xge/SDL_Engine.h"
#include "xge/engine_exception.h"
#include "xge/logger.h"
#include <string>

bool Engine::init(Platform &platform) {
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD | SDL_INIT_AUDIO)) {
        ThrowException("SDL_Init failed.", SDL_GetError());
        return false;
    }

    LOG("XGE-SDL", (std::string("SDL_Init success! Using Driver: ")
        + SDL_GetCurrentVideoDriver()).c_str());
    LOG("XGE-SDL", "Creating SDL window...");

    platform.window = SDL_CreateWindow(
        "X-Game-Engine",
        1280,
        720,
        SDL_WINDOW_RESIZABLE | SDL_WINDOW_VULKAN
    );

    if (!platform.window) {
        ThrowException("SDL window failed.", SDL_GetError());
        return false;
    }

    LOG("XGE-SDL", "Window created, updating surface and showing to screen...");

    SDL_Surface *surface = SDL_GetWindowSurface(platform.window);
    SDL_UpdateWindowSurface(platform.window);
    SDL_ShowWindow(platform.window);

    LOG("XGE-SDL", "Initialization complete!");

    return true;
}

void Engine::run(Platform &platform) {
    LOG("XGE-SDL", "Starting SDL engine loop...");
    Uint64 last = SDL_GetTicks();

    while (platform.running) {
        const Uint64 now = SDL_GetTicks();
        const auto deltaTime = static_cast<double>(now - last);
        last = now;

        processEvents(platform);
        update(deltaTime);
        render();
    }

    LOG("XGE-SDL", "SDL loop terminated, running shutdown sequence...");

    shutdown(platform);
}

void Engine::processEvents(Platform &platform) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            LOG("XGE-SDL", "SDL quit event called by user, terminating SDL loop...");
            platform.running = false;
        }
    }
}

void Engine::update(const double deltaTime) {
    (void)deltaTime;
}

void Engine::render() {
    //TODO: Render API
}

void Engine::shutdown(const Platform &platform) {
    SDL_DestroyWindow(platform.window);
    LOG("XGE-SDL-Shutdown", "Destroyed SDL window.");
    SDL_Quit();
    LOG("XGE-SDL-Shutdown", "SDL cleaned.");
}
