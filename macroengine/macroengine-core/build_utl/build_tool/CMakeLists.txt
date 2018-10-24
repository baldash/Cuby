cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)
include_directories(..)
include_directories(../../arguments-parser/arguments-parser)
include_directories(../../arguments-parser)
include_directories(../utl)

set(BUILD_DIRECTORY ${PROJECT_SOURCE_DIR})#/../../../)

add_executable(build-tool main.cpp ../utl/Directory/Directory.cpp ../utl/Directory/Directory.hpp ../utl/IniParser/IniParser.hpp ../utl/IniParser/IniParser.cpp ../utl/IniParser/IniScope.cpp ../utl/IniParser/IniScope.hpp ../utl/File/File.cpp ../utl/File/File.hpp StringsFinder/StringsFinder.cpp StringsFinder/StringsFinder.hpp commands/InstallDirectory/InstallDirectory.hpp commands/InstallDirectory/InstallDirectory.cpp commands/BuildDirectory/BuildDirectory.hpp commands/BuildDirectory/BuildDirectory.cpp commands/Install/Install.hpp commands/Install/Install.cpp commands/Build/Build.hpp commands/Build/Build.cpp commands/Clean/Clean.hpp commands/Clean/Clean.cpp BuildTool/BuildTool.hpp BuildTool/BuildTool.cpp commands/Help/Help.cpp commands/Help/Help.hpp commands/commands.hpp)

add_subdirectory(../../arguments-parser libarguments-parser.so)
add_dependencies(build-tool arguments-parser)

set(CMAKE_CXX_FLAGS "-W -Wall -Wextra -g -ggdb3")

target_link_libraries(build-tool arguments-parser stdc++fs)

set(EXECUTABLE_OUTPUT_PATH ${BUILD_DIRECTORY})
