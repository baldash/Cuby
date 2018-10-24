/*
** TestFile.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/tests/utl/File/TestFile.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Jan 26 15:59:52 2018 Sylvain CHAUGNY
*/

#include "macroengine-core/file/File/File.hpp"
#include "gtest/gtest.h"

TEST(TestFile, General)
{
  macroengine::file::File file;

  file.open();
  EXPECT_EQ(file.good(), false);
  file.setFileName("file/File/unexistant_file");
  file.open();
  file.close();
  EXPECT_EQ(file.good(), false);
  file.setFileName("file/File/empty_file.txt");
  file.open();
  file.read();
  EXPECT_EQ(file.getContent().size(), 0);
  file.close();
  file.setFileName("file/File/test_file1.txt");
  file.open();
  EXPECT_EQ(file.good(), true);
  EXPECT_EQ(file.read(), 0);
  EXPECT_EQ(file.getContent().size(), 4);
  EXPECT_EQ(file.getContent()[2], "a");
  EXPECT_EQ(file.getContent()[3], "test");
  file.close();
  file.setFileName("file/File/test_file2.txt");
  file.open();
  EXPECT_EQ(file.read(), 0);
  EXPECT_EQ(file.getContent()[2], "ijkl");
  EXPECT_EQ(file.getContent()[0], "abcd");
  file.close();
}
