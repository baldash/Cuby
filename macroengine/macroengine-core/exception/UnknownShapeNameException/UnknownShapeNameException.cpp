/*
** UnknownShapeNameException.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/UnknownShapeNameException/UnknownShapeNameException.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 02:19:59 2018 Sylvain CHAUGNY
*/

#include			"UnknownShapeNameException.hpp"

macroengine::exception::UnknownShapeNameException::UnknownShapeNameException(std::string const &str) noexcept :
  _what(str) {
}

const char			*macroengine::exception::UnknownShapeNameException::what() const throw() {
  return _what.c_str();
}
