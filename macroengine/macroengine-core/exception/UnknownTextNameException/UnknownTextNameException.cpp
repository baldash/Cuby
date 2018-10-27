/*
** UnknownTextNameException.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/UnknownTextNameException/UnknownTextNameException.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 02:19:59 2018 Sylvain CHAUGNY
*/

#include			"UnknownTextNameException.hpp"

macroengine::exception::UnknownTextNameException::UnknownTextNameException(std::string const &str) noexcept :
  _what(str) {
}

const char			*macroengine::exception::UnknownTextNameException::what() const throw() {
  return _what.c_str();
}
