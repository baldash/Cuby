/*
** IniScope.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/parser/ini/IniScope/IniScope.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon Feb 05 21:17:35 2018 Sylvain CHAUGNY
*/

#include						"IniScope.hpp"

void							macroengine::build_utl::parser::IniScope::setName(std::string const &name) {
  _name = name;
}

void							macroengine::build_utl::parser::IniScope::addEntry(std::string const &key, std::string const &value) {
  _content[key] = value;
}

std::string const					&macroengine::build_utl::parser::IniScope::getName() {
  return _name;
}

std::string const					&macroengine::build_utl::parser::IniScope::operator[](std::string const &key) const {
  try {
    return _content.at(key);
  } catch (...) {
    return _empty;
  }
}

size_t							macroengine::build_utl::parser::IniScope::getSize() const {
  return _content.size();
}

const macroengine::build_utl::parser::IniScope::t_ini_scope	&macroengine::build_utl::parser::IniScope::getContent() const {
  return _content;
}

bool 							macroengine::build_utl::parser::IniScope::keyExists(std::string const &key) const {
  return _content.find(key) != _content.end();
}
