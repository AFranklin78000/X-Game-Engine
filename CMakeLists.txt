cmake_minimum_required(VERSION 4.1)
project(X_Game_Engine)

set(CMAKE_CXX_STANDARD 20)

include_directories(include/com/afirex)

add_executable(X_Game_Engine src/com/afirex/xge/main.cpp)

