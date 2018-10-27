/*
** IniScope.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/parser/ini/IniScope/IniScope.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon Feb 05 21:17:35 2018 Sylvain CHAUGNY
*/

#include						"IniScope.hpp"

macroengine::parser::ini::IniScope::IniScope() :
  Object("IniScope") {
}

void							macroengine::parser::ini::IniScope::dump() {
}

void							macroengine::parser::ini::IniScope::setName(std::string const &name) {
  _name = name;
}

void							macroengine::parser::ini::IniScope::addEntry(std::string const &key, std::string const &value) {
  _content[key] = value;
}

std::string const					&macroengine::parser::ini::IniScope::getName() const {
  return _name;
}

std::string const					&macroengine::parser::ini::IniScope::operator[](std::string const &key) const {
  try {
    return _content.at(key);
  } catch (...) {
    return _empty;
  }
}

size_t 							macroengine::parser::ini::IniScope::getSize() const {
  return _content.size();
}

const macroengine::parser::ini::t_ini_scope		&macroengine::parser::ini::IniScope::getContent() const {
  return _content;
}

bool 							macroengine::parser::ini::IniScope::keyExists(std::string const &key) const {
  return _content.find(key) != _content.end();
}
