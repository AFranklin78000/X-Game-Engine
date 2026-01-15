//
// Created by afirex on 1/12/26.
//

#include "xge/logger.h"

int main() {
    OPEN_LOG();
    LOG_STATISTICS(true);
    LOG("XGE-Main", "Starting X-Game-Engine; welcome!");
    LOG("XGE-Main", "Beginning engine initialization...");

    LOG("XGE-Main", "Beginning SDL window initialization...");



    CLOSE_LOG();
    return 0;
}