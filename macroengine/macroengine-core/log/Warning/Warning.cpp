/*
** Warning.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/log/Warning/Warning.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Jan 24 21:26:27 2018 Sylvain CHAUGNY
*/

#include			<iostream>
#include			"Warning.hpp"

void				macroengine::log::Warning::display(std::string const &str) {
  std::cout << MACROENGINE_LOG_WARNING_HEADER << str << std::endl;
}

macroengine::log::Warning::Warning(const std::string &str) {
  display(str);
}
