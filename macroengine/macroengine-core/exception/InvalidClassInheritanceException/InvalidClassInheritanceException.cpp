/*
** InvalidClassInheritanceException.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/InvalidClassInheritanceException/InvalidClassInheritanceException.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 22:46:29 2018 Sylvain CHAUGNY
*/

#include 			"InvalidClassInheritanceException.hpp"

macroengine::exception::InvalidClassInheritanceException::InvalidClassInheritanceException(std::string const &str) noexcept :
  _what(str) {
}

const char			*macroengine::exception::InvalidClassInheritanceException::what() const throw() {
  return _what.c_str();
}