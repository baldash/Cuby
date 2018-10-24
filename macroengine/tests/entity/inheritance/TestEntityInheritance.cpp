/*
** TestEntityInheritance.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/tests/utl/File/TestEntityInheritance.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Jan 26 15:59:52 2018 Sylvain CHAUGNY
*/

#include <gtest/gtest.h>
#include <macroengine-core/entity/property/Collidable/Collidable.hpp>
#include <macroengine-core/entity/property/Controllable/Controllable.hpp>
#include <macroengine-core/entity/property/Movable/Movable.hpp>
#include <macroengine-core/entity/property/Drawable/Drawable.hpp>

class testCollidable : public macroengine::property::Collidable
{};

class testCollidableControllable : public macroengine::property::Collidable,
				   public macroengine::property::Controllable
{};

class testCollidableControllableMovable : public macroengine::property::Collidable,
					  public macroengine::property::Controllable,
					  public macroengine::property::Movable
{};

class testCollidableControllableMovableDrawable : public macroengine::property::Collidable,
						  public macroengine::property::Controllable,
						  public macroengine::property::Movable,
						  public macroengine::property::Drawable<macroengine::property::SPRITE | macroengine::property::ANIMATION>

{};

TEST(TestEntityInheritance, Collidable)
{
  testCollidable c;

  ASSERT_EQ(true, c.getPermissions().contains(macroengine::property::COLLIDABLE));
  ASSERT_EQ(false, c.getPermissions().contains(macroengine::property::CONTROLLABLE));
  ASSERT_EQ(false, c.getPermissions().contains(macroengine::property::MOVABLE));
  ASSERT_EQ(false, c.getPermissions().contains(macroengine::property::DRAWABLE));
}

TEST(TestEntityInheritance, CollidableControllable)
{
  testCollidableControllable c;

  ASSERT_EQ(true, c.getPermissions().contains(macroengine::property::COLLIDABLE));
  ASSERT_EQ(true, c.getPermissions().contains(macroengine::property::CONTROLLABLE));
  ASSERT_EQ(false, c.getPermissions().contains(macroengine::property::MOVABLE));
  ASSERT_EQ(false, c.getPermissions().contains(macroengine::property::DRAWABLE));
}

TEST(TestEntityInheritance, CollidableControllableMovable)
{
  testCollidableControllableMovable c;

  ASSERT_EQ(true, c.getPermissions().contains(macroengine::property::COLLIDABLE));
  ASSERT_EQ(true, c.getPermissions().contains(macroengine::property::CONTROLLABLE));
  ASSERT_EQ(true, c.getPermissions().contains(macroengine::property::MOVABLE));
  ASSERT_EQ(false, c.getPermissions().contains(macroengine::property::DRAWABLE));
}

TEST(TestEntityInheritance, CollidableControllableMovableDrawable)
{
  testCollidableControllableMovableDrawable c;

  ASSERT_EQ(true, c.getPermissions().contains(macroengine::property::COLLIDABLE));
  ASSERT_EQ(true, c.getPermissions().contains(macroengine::property::CONTROLLABLE));
  ASSERT_EQ(true, c.getPermissions().contains(macroengine::property::MOVABLE));
  ASSERT_EQ(true, c.getPermissions().contains(macroengine::property::DRAWABLE));
  ASSERT_EQ(true, c.getPermissionProperties(macroengine::property::DRAWABLE).contains(macroengine::property::SPRITE));
  ASSERT_EQ(true, c.getPermissionProperties(macroengine::property::DRAWABLE).contains(macroengine::property::ANIMATION));
  ASSERT_EQ(false, c.getPermissionProperties(macroengine::property::DRAWABLE).contains(macroengine::property::TEXT));
}
