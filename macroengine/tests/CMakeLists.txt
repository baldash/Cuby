cmake_minimum_required(VERSION 3.8)

include_directories(../ ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(macroengine_tests utl/BitMask/TestBitMask.cpp file/File/TestFile.cpp parser/ini/IniParser/TestIniParser.cpp parser/ini/IniScope/TestIniScope.cpp entity/inheritance/TestEntityInheritance.cpp configuration/strings/StringBuilder/TestStringBuilder.cpp configuration/strings/StringBuilder/TestStringBuilderStringFile.cpp)

set(CMAKE_CXX_FLAGS "-g -ggdb3")

target_link_libraries(macroengine_tests macroengine gtest gtest_main pthread)

add_dependencies(macroengine_tests macroengine)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
