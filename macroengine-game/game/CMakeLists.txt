cmake_minimum_required(VERSION 3.8)

include_directories(.)

add_executable(macroengine-game main.cpp entities/MapFactory/MapFactory.cpp entities/MapFactory/MapFactory.hpp entities/MapLevel/MapLevel.cpp entities/MapLevel/MapLevel.hpp entities/MenuController/MenuController.cpp entities/MenuController/MenuController.hpp entities/Game/Game.cpp entities/Game/Game.hpp entities/Player/Player.cpp entities/Player/Player.hpp entities/PlayerFactory/PlayerFactory.cpp entities/PlayerFactory/PlayerFactory.hpp)

target_link_libraries(macroengine-game macroengine macroengine-rpg sfml-system sfml-graphics sfml-window)

set(CMAKE_CXX_FLAGS "-W -Wall -Wextra -g -ggdb3")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
