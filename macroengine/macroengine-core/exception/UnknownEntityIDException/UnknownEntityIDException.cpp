/*
** UnknownEntityID.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/UnknownEntityID/UnknownEntityID.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 02:19:18 2018 Sylvain CHAUGNY
*/

#include			"UnknownEntityIDException.hpp"

macroengine::exception::UnknownEntityIDException::UnknownEntityIDException(std::string const &str) noexcept :
  _what(str) {
}

const char			*macroengine::exception::UnknownEntityIDException::what() const throw() {
  return _what.c_str();
}