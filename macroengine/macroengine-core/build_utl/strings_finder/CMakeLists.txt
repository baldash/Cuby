cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)
include_directories(..)
include_directories(../utl)

add_executable(strings_finder main.cpp ../utl/Directory/Directory.cpp ../utl/Directory/Directory.hpp
        ../utl/IniParser/IniParser.hpp ../utl/IniParser/IniParser.cpp
        ../utl/IniParser/IniScope.cpp ../utl/IniParser/IniScope.hpp
        ../utl/File/File.cpp ../utl/File/File.hpp StringsFinder/StringsFinder.cpp StringsFinder/StringsFinder.hpp)

add_custom_target(findStrings ALL COMMAND ${BUILD_DIRECTORY}/strings_finder ${PROJECT_SOURCE_DIR})

add_dependencies(findStrings strings_finder)

set(CMAKE_CXX_FLAGS "-W -Wall -Wextra -g -ggdb3")

target_link_libraries(strings_finder stdc++fs)

set(EXECUTABLE_OUTPUT_PATH ${BUILD_DIRECTORY})
