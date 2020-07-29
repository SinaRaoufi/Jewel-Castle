cmake_minimum_required(VERSION 3.0)
project(JewelCastle)
set(CMAKE_CXX_STANDARD 11)
include_directories(include)
target_link_libraries(JewelCastle sfml-window sfml-system sfml-graphics)
add_executable(JewelCastle 
    src/main.cpp
    src/Game.cpp
    src/GameState.cpp
    src/MainMenuState.cpp
    src/PlayState.cpp
    src/Button.cpp
    src/Tile.cpp
    src/Board.cpp)