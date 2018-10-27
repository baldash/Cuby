/*
** TestIniParser.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/tests/parser/ini/TestIniParser.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon Feb 05 21:28:30 2018 Sylvain CHAUGNY
*/

#include "macroengine-core/parser/ini/IniParser/IniParser.hpp"
#include "gtest/gtest.h"

TEST(TestIniParser, RegularCase)
{
  macroengine::parser::ini::IniParser parser;
  macroengine::file::File file;

  file.setFileName("parser/ini/IniParser/test_regular.ini");
  file.open();
  if (!file.good() || file.read())
    return ;
  EXPECT_EQ(parser.parseFromFile(file), 0);
  EXPECT_EQ(parser["TEST"]["a"], "b");
  EXPECT_EQ(parser["TEST"]["b"], "");
  EXPECT_EQ(parser["TEST"]["c"], "d");
  EXPECT_EQ(parser["TEST"]["e"], "f			t		b");
  EXPECT_EQ(parser["TEST"]["g"], "h");
  EXPECT_EQ(parser["COUCOU"]["a"], "");
  EXPECT_EQ(parser["COUCOU"]["i"], "j");
  EXPECT_EQ(parser["COUCOU"]["k"], "l");
  EXPECT_EQ(parser["COUCOU"]["l"], "\"e\"");
}

TEST(TestIniParser, EmptyFileCase)
{
  macroengine::parser::ini::IniParser parser;
  macroengine::file::File file;

  file.setFileName("parser/ini/IniParser/test_empty.ini");
  file.open();
  if (!file.good() || file.read())
    return ;
  EXPECT_EQ(parser.parseFromFile(file), 0);
  EXPECT_EQ(parser["TEST"].getSize(), 0);
  EXPECT_NE(parser["TEST"]["TEST2"], "a");
}

TEST(TestIniParser, FailCase1)
{
  macroengine::parser::ini::IniParser parser;
  macroengine::file::File file;

  file.setFileName("parser/ini/IniParser/test_fail1.ini");
  file.open();
  if (!file.good() || file.read())
    return ;
  EXPECT_EQ(parser.parseFromFile(file), 1);
}

TEST(TestIniParser, FailCase2)
{
  macroengine::parser::ini::IniParser parser;
  macroengine::file::File file;

  file.setFileName("parser/ini/IniParser/test_fail2.ini");
  file.open();
  if (!file.good() || file.read())
    return ;
  EXPECT_EQ(parser.parseFromFile(file), 1);
}

TEST(TestIniParser, FailCase3)
{
  macroengine::parser::ini::IniParser parser;
  macroengine::file::File file;

  file.setFileName("parser/ini/IniParser/test_fail3.ini");
  file.open();
  if (!file.good() || file.read())
    return ;
  EXPECT_EQ(parser.parseFromFile(file), 1);
}

TEST(TestIniParser, MultiLineCase)
{
  macroengine::parser::ini::IniParser parser;
  macroengine::file::File file;

  file.setFileName("parser/ini/IniParser/test_multiline.ini");
  file.open();
  if (!file.good() || file.read())
    return ;
  EXPECT_EQ(parser.parseFromFile(file), 0);
  EXPECT_EQ(parser["COUCOU"].getSize(), 6);
  EXPECT_EQ(parser["COUCOU"]["test1"], "1");
  EXPECT_EQ(parser["COUCOU"]["test2"], "2");
  EXPECT_EQ(parser["COUCOU"]["test3"], "coucou\nca\nva\n?");
  EXPECT_EQ(parser["COUCOU"]["test4"], "coucou\n\nca\nva\n?");
  EXPECT_EQ(parser["COUCOU"]["test5"], "coucou\nca\nva ?");
  EXPECT_EQ(parser["COUCOU"]["test6"], "coucou\nca\nva ?");

  EXPECT_EQ(parser["COUCOU2"].getSize(), 4);
  EXPECT_EQ(parser["COUCOU2"]["test7"], "coucou\nca\nva ?");
  EXPECT_EQ(parser["COUCOU2"]["test8"], "coucou\nca\nva ?");
  EXPECT_EQ(parser["COUCOU2"]["test9"], "coucou\nca va ?");
  EXPECT_EQ(parser["COUCOU2"]["test10"], "cou\"co\"u\nca v\"a ?");
}

TEST(TestIniParser, MultilineFailCase1)
{
  macroengine::parser::ini::IniParser parser;
  macroengine::file::File file;

  file.setFileName("parser/ini/IniParser/test_multiline_fail.ini");
  file.open();
  if (!file.good() || file.read())
    return ;
  EXPECT_EQ(parser.parseFromFile(file), 1);
}
