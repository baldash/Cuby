/*
** s_identifier.cpp for macroengine in /home/sylvain/Documents/projets/perso/macroengine/macroengine/utl/struct/s_identifier.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed May 02 13:18:32 2018 Sylvain CHAUGNY
*/

#include			"s_identifier.hpp"

macroengine::utl::s_identifier::s_identifier() :
  id(-1),
  name("") {
}

macroengine::utl::s_identifier::s_identifier(long id, std::string const &name) :
  id(id),
  name(name) {
}

macroengine::utl::s_identifier::s_identifier(const macroengine::utl::s_identifier &op) :
  id(op.id),
  name(op.name) {
}

macroengine::utl::s_identifier	&macroengine::utl::s_identifier::operator=(const macroengine::utl::s_identifier &op) {
  name = op.name;
  id = op.id;
  return *this;
}

bool				macroengine::utl::s_identifier::operator==(const macroengine::utl::s_identifier &op) const {
  return id == op.id && name == op.name;
}

bool				macroengine::utl::s_identifier::operator!=(const macroengine::utl::s_identifier &op) const {
  return id != op.id || name != op.name;
}

bool				macroengine::utl::s_identifier::operator<(const macroengine::utl::s_identifier &op) const {
  return id < op.id;
}

bool				macroengine::utl::s_identifier::operator>(const macroengine::utl::s_identifier &op) const {
  return id > op.id;
}

std::string			macroengine::utl::s_identifier::getDebugString() const {
  return "[id = " + std::to_string(id) + ", name = <" + name + ">]";
}

bool				macroengine::utl::s_identifier::filled() const {
  return id != -1 && !name.empty();
}

bool				macroengine::utl::s_identifier::empty() const {
  return id == -1 && name.empty();
}
