/*
** TestIniScope.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/tests/parser/ini/TestIniScope.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon Feb 05 21:29:42 2018 Sylvain CHAUGNY
*/

#include "macroengine-core/parser/ini/IniScope/IniScope.hpp"
#include "gtest/gtest.h"

TEST(TestIniScope, General)
{
  macroengine::parser::ini::IniScope scope;

  EXPECT_EQ(scope.getName(), "");
  EXPECT_EQ(scope["test"].size(), 0);
  EXPECT_EQ(scope.getSize(), 0);
  scope.setName("test_name");
  scope.addEntry("key1", "value1");
  scope.addEntry("key2", "value2");
  EXPECT_EQ(scope.getSize(), 2);
  EXPECT_EQ(scope.getName(), "test_name");
  EXPECT_EQ(scope["key1"], "value1");
  EXPECT_EQ(scope["key2"], "value2");
  EXPECT_NE(scope["key3"], "value3");
  scope.addEntry("key3", "value3");
  scope.addEntry("key1", "value1_2");
  EXPECT_EQ(scope["key3"], "value3");
  EXPECT_EQ(scope["key1"], "value1_2");
  EXPECT_EQ(scope.getSize(), 3);
}
