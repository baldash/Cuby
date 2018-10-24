/*
** UnknownViewIDException.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/UnknownViewIDException/UnknownViewIDException.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 02:19:59 2018 Sylvain CHAUGNY
*/

#include			"UnknownViewIDException.hpp"

macroengine::exception::UnknownViewIDException::UnknownViewIDException(std::string const &str) noexcept :
  _what(str) {
}

const char			*macroengine::exception::UnknownViewIDException::what() const throw() {
  return _what.c_str();
}
