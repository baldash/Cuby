/*
** TestStringBuilderStringFile.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/tests/configuration/strings/StringBuilder/TestStringBuilderStringFile.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sat Feb 17 22:04:45 2018 Sylvain CHAUGNY
*/

#include			<gtest/gtest.h>
#include			"macroengine-core/macroengine-core.hpp"

TEST(TestStringBuilder, StringFileOK)
{
  setDebugMode(MACROENGINE_VAR_DEBUG_MODE_CONFIGURATION_ONLY);
  ASSERT_EQ(runEngine(), 0);
  ASSERT_EQ(Strings("test1", std::string("test1"), std::string("test2"), std::string("test3")), "a");
  ASSERT_EQ(Strings("test2", std::string("test1"), std::string("test2"), std::string("test3")), "b test1 test2");
  ASSERT_EQ(stopEngine(), 0);
}
