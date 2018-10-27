/*
** BadPermissionException.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/BadPermissionException/BadPermissionException.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Feb 15 18:57:24 2018 Sylvain CHAUGNY
*/

#include			"BadPermissionException.hpp"

macroengine::exception::BadPermissionException::BadPermissionException(std::string const &str) noexcept :
  _what(str) {
}

const char			*macroengine::exception::BadPermissionException::what() const throw() {
  return _what.c_str();
}