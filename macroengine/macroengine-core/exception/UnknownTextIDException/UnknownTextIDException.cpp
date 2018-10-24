/*
** UnknownTextIDException.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/UnknownTextIDException/UnknownTextIDException.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 02:19:59 2018 Sylvain CHAUGNY
*/

#include			"UnknownTextIDException.hpp"

macroengine::exception::UnknownTextIDException::UnknownTextIDException(std::string const &str) noexcept :
  _what(str) {
}

const char			*macroengine::exception::UnknownTextIDException::what() const throw() {
  return _what.c_str();
}
