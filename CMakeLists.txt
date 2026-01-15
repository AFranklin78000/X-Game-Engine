cmake_minimum_required(VERSION 4.1)
project(X_Game_Engine)

set(CMAKE_CXX_STANDARD 20)
set(XGE src/com/afirex/xge)
set(XGEh include/com/afirex/xge)

add_library(BASE_ENGINE ${XGE}/logger.cpp ${XGEh}/Platform.h ${XGE}/SDL_Engine.cpp)

find_package(SDL3 REQUIRED)

include_directories(include/com/afirex)

add_executable(X_Game_Engine ${XGE}/main.cpp)

target_link_libraries(X_Game_Engine PRIVATE BASE_ENGINE)
target_link_libraries(X_Game_Engine PRIVATE SDL3::SDL3)

