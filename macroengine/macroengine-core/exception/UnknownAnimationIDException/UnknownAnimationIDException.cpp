/*
** UnknownAnimationIDException.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/UnknownAnimationIDException/UnknownAnimationIDException.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 02:19:59 2018 Sylvain CHAUGNY
*/

#include			"UnknownAnimationIDException.hpp"

macroengine::exception::UnknownAnimationIDException::UnknownAnimationIDException(std::string const &str) noexcept :
  _what(str) {
}

const char			*macroengine::exception::UnknownAnimationIDException::what() const throw() {
  return _what.c_str();
}
