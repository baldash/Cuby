/*
** UnknownKeyboardActionIDException.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/UnknownKeyboardActionIDException/UnknownKeyboardActionIDException.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 02:19:59 2018 Sylvain CHAUGNY
*/

#include			"UnknownKeyboardActionIDException.hpp"

macroengine::exception::UnknownKeyboardActionIDException::UnknownKeyboardActionIDException(std::string const &str) noexcept :
  _what(str) {
}

const char			*macroengine::exception::UnknownKeyboardActionIDException::what() const throw() {
  return _what.c_str();
}
