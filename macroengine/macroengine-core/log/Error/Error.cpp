/*
** Error.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/log/Error/Error.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Jan 24 21:18:24 2018 Sylvain CHAUGNY
*/

#include			<iostream>
#include			"Error.hpp"

void				macroengine::log::Error::display(std::string const &str) {
  std::cerr << MACROENGINE_LOG_ERROR_HEADER << str << std::endl;
}

macroengine::log::Error::Error(std::string const &str) {
  display(str);
}