/*
** UnknownKeyboardActionNameException.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/UnknownKeyboardActionNameException/UnknownKeyboardActionNameException.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 02:19:59 2018 Sylvain CHAUGNY
*/

#include			"UnknownKeyboardActionNameException.hpp"

macroengine::exception::UnknownKeyboardActionNameException::UnknownKeyboardActionNameException(std::string const &str) noexcept :
  _what(str) {
}

const char			*macroengine::exception::UnknownKeyboardActionNameException::what() const throw() {
  return _what.c_str();
}
