/*
** NoCurrentAnimationSelectedException.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/NoCurrentAnimationSelectedException/NoCurrentAnimationSelectedException.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Mar 01 23:28:45 2018 Sylvain CHAUGNY
*/

#include			"NoCurrentAnimationSelectedException.hpp"

macroengine::exception::NoCurrentAnimationSelectedException::NoCurrentAnimationSelectedException(std::string const &str) noexcept :
  _what(str) {
}

const char			*macroengine::exception::NoCurrentAnimationSelectedException::what() const throw() {
  return _what.c_str();
}