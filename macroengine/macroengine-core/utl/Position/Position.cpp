/*
** Position.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/utl/Position/Position.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 01:19:28 2018 Sylvain CHAUGNY
*/

#include			"Position.hpp"

macroengine::utl::Position::Position(float _x, float _y) :
  x(_x),
  y(_y) {
}

macroengine::utl::Position::Position(const macroengine::utl::Position &pos) :
  x(pos.x),
  y(pos.y) {
}

macroengine::utl::Position::Position(sf::Vector2i const &pos) :
  x(pos.x),
  y(pos.y) {
}

macroengine::utl::Position	&macroengine::utl::Position::operator=(const macroengine::utl::Position &pos) {
  x = pos.x;
  y = pos.y;
  return *this;
}

macroengine::utl::Position	&macroengine::utl::Position::operator=(sf::Vector2i const &pos) {
  x = pos.x;
  y = pos.y;
  return *this;
}

bool				macroengine::utl::Position::operator==(sf::Vector2i const &pos) const {
  return pos.x == x && pos.y == y;
}

bool				macroengine::utl::Position::operator==(const macroengine::utl::Position &pos) const {
  return pos.x == x && pos.y == y;
}

sf::Vector2f			macroengine::utl::Position::toSfVector2f() {
  return sf::Vector2f(x, y);
}

bool				macroengine::utl::Position::operator<(const macroengine::utl::Position &pos) const {
  return x < pos.x && y < pos.y;
}

bool				macroengine::utl::Position::operator>=(const macroengine::utl::Position &pos) const {
  return x >= pos.x && y >= pos.y;
}

bool				macroengine::utl::Position::operator>(const macroengine::utl::Position &pos) const {
  return x > pos.x && y > pos.y;
}

bool				macroengine::utl::Position::operator<=(const macroengine::utl::Position &pos) const {
  return x <= pos.x && y <= pos.y;
}

bool				macroengine::utl::Position::operator!=(const macroengine::utl::Position &pos) const {
  return x != pos.x || y != pos.y;
}
