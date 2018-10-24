cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

project(Macro_Engine)

set(INSTALL_DIRECTORY /usr/local)

add_subdirectory(macroengine-core)
add_subdirectory(macroengine-rpg)
add_subdirectory(tests)
