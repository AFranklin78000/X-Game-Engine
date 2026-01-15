//
// Created by afirex on 1/12/26.
//

#include "xge/logger.h"
#include "xge/Platform.h"
#include "xge/SDL_Engine.h"

int main() {
    OPEN_LOG();
    LOG_STATISTICS(true);
    LOG("XGE-Main", "Starting X-Game-Engine; welcome!");
    LOG("XGE-Main", "Beginning engine initialization...");

    LOG("XGE-Main", "Beginning SDL window initialization...");

    Platform platform;
    Engine engine;
    if (!engine.init(platform)) {
        CLOSE_LOG();
        return -1;
    }

    engine.run(platform);

    CLOSE_LOG();
    return 0;
}
