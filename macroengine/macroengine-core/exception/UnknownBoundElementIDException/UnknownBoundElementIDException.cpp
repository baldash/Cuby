/*
** UnknownBoundElementIDException.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/UnknownBoundElementIDException/UnknownBoundElementIDException.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 02:19:59 2018 Sylvain CHAUGNY
*/

#include			"UnknownBoundElementIDException.hpp"

macroengine::exception::UnknownBoundElementIDException::UnknownBoundElementIDException(std::string const &str) noexcept :
  _what(str) {
}

const char			*macroengine::exception::UnknownBoundElementIDException::what() const throw() {
  return _what.c_str();
}
