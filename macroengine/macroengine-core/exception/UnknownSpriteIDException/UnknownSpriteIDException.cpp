/*
** UnknownSpriteID.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/UnknownSpriteID/UnknownSpriteID.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 02:19:18 2018 Sylvain CHAUGNY
*/

#include			"UnknownSpriteIDException.hpp"

macroengine::exception::UnknownSpriteIDException::UnknownSpriteIDException(std::string const &str) noexcept :
  _what(str) {
}

const char			*macroengine::exception::UnknownSpriteIDException::what() const throw() {
  return _what.c_str();
}