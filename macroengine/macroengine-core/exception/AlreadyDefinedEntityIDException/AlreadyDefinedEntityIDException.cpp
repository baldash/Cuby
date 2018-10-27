/*
** AlreadyDefinedEntityIDException.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/AlreadyDefinedEntityIDException/AlreadyDefinedEntityIDException.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 22:46:29 2018 Sylvain CHAUGNY
*/

#include 			"AlreadyDefinedEntityIDException.hpp"

macroengine::exception::AlreadyDefinedEntityIDException::AlreadyDefinedEntityIDException(std::string const &str) noexcept :
  _what(str) {
}

const char			*macroengine::exception::AlreadyDefinedEntityIDException::what() const throw() {
  return _what.c_str();
}