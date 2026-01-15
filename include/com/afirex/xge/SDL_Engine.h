//
// Created by afirex on 1/14/26.
//

#ifndef X_GAME_ENGINE_ENGINE_H
#define X_GAME_ENGINE_ENGINE_H

#include "xge/Platform.h"

class Engine {
public:
    bool init(Platform &platform);
    void run(Platform &platform);
    void shutdown(const Platform &platform);

private:
    void processEvents(Platform &platform);
    void update(double deltaTime);
    void render();

};


#endif