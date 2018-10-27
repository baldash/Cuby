cmake_minimum_required(VERSION 3.8)

include_directories(../)
include_directories(../)

set(BUILD_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../.lib)

add_library(macroengine-rpg SHARED map/Cell/Cell.cpp map/Cell/Cell.hpp map/Map/Map.cpp map/Map/Map.hpp macroengine-rpg.hpp map/map.hpp utl/macros/macros_definitions.hpp utl/rpg_types.hpp map/CellData/CellData.hpp map/CellData/CellData.cpp character/Player/Player.cpp character/Player/Player.hpp character/Character/Character.cpp character/Character/Character.hpp character/utl/CharacterStatistics/CharacterStatistics.cpp character/utl/CharacterStatistics/CharacterStatistics.hpp character/utl/PlayerParameters/PlayerParameters.cpp character/utl/PlayerParameters/PlayerParameters.hpp character/utl/enum/e_player_keys.hpp character/character.hpp)

add_dependencies(macroengine-rpg macroengine)

set(CMAKE_CXX_FLAGS "-W -Wall -Wextra -g -ggdb3")

set(LIBRARY_OUTPUT_PATH ${BUILD_DIRECTORY})

target_link_libraries(macroengine-rpg macroengine)

install(TARGETS macroengine-rpg LIBRARY DESTINATION ${INSTALL_DIRECTORY}/lib)
install(DIRECTORY ${BUILD_DIRECTORY}/../macroengine-rpg/ DESTINATION ${INSTALL_DIRECTORY}/include/macroengine-rpg FILES_MATCHING PATTERN "*.hpp")
