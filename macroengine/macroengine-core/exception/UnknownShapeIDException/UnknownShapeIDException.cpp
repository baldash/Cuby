/*
** UnknownShapeID.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/UnknownShapeID/UnknownShapeID.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 02:19:18 2018 Sylvain CHAUGNY
*/

#include			"UnknownShapeIDException.hpp"

macroengine::exception::UnknownShapeIDException::UnknownShapeIDException(std::string const &str) noexcept :
  _what(str) {
}

const char			*macroengine::exception::UnknownShapeIDException::what() const throw() {
  return _what.c_str();
}