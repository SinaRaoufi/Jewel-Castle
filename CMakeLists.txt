cmake_minimum_required(VERSION 3.0)
project(JewelCastle)
set(CMAKE_CXX_STANDARD 11)
include_directories(include)
add_executable(JewelCastle 
    src/main.cpp
    src/Game.cpp
    src/GameState.cpp
    src/MainMenuState.cpp
    src/PlayState.cpp
    src/PauseState.cpp
    src/WinState.cpp
    src/LostState.cpp
    src/Button.cpp
    src/RandomNumberGenerator.cpp
    src/Tile.cpp
    src/Board.cpp
    src/Jewel.cpp
    src/GreenJewel.cpp
    src/BlueJewel.cpp
    src/VioletJewel.cpp
    src/YellowJewel.cpp
    src/RedJewel.cpp
    src/PinkJewel.cpp
    src/Move.cpp
    src/Score.cpp
    src/Timer.cpp
    src/Ability.cpp
    src/MagnetAbility.cpp
    src/FistAbility.cpp
    src/BombAbility.cpp)
    target_link_libraries(JewelCastle sfml-window sfml-system sfml-graphics sfml-audio)