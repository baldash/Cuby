/*
** BadFormattedStringException.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/BadFormattedStringException/BadFormattedStringException.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 22:46:29 2018 Sylvain CHAUGNY
*/

#include 			"BadFormattedStringException.hpp"

macroengine::exception::BadFormattedStringException::BadFormattedStringException(std::string const &str) noexcept :
  _what(str) {
}

const char			*macroengine::exception::BadFormattedStringException::what() const throw() {
  return _what.c_str();
}