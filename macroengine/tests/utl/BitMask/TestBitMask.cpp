/*
** TestBitMask.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/tests/utl/BitMask/TestBitMask.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Jan 24 21:59:47 2018 Sylvain CHAUGNY
*/

#include "macroengine-core/utl/BitMask/BitMask.hpp"
#include "macroengine-core/entity/property/enum/e_property.hpp"
#include "gtest/gtest.h"

TEST(TestBitMask, General)
{
  macroengine::utl::BitMask mask;

  mask.add(2);
  mask.add(8);
  EXPECT_EQ(mask.contains(2), true);
  EXPECT_EQ(mask.contains(8), true);
  EXPECT_EQ(mask.contains(9), false);
  EXPECT_EQ(mask.contains(8192), false);
  mask.add(8192);
  EXPECT_EQ(mask.contains(8192), true);
}

TEST(TestBitMask, Contextualized)
{
  macroengine::utl::BitMask mask;

  mask.add(macroengine::property::DRAWABLE);
  mask.add(macroengine::property::CONTROLLABLE);

  EXPECT_EQ(mask.contains(macroengine::property::DRAWABLE), true);
  EXPECT_EQ(mask.contains(macroengine::property::CONTROLLABLE), true);
  EXPECT_EQ(mask.contains(macroengine::property::COLLIDABLE), false);
  mask.add(macroengine::property::COLLIDABLE);
  EXPECT_EQ(mask.contains(macroengine::property::COLLIDABLE), true);
}
