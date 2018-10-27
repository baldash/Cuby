/*
** Error.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/log/Error/Error.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Jan 24 21:18:24 2018 Sylvain CHAUGNY
*/

#include			<iostream>
#include			"Dump.hpp"

void				macroengine::log::Dump::display(std::string const &str) {
  std::cerr << MACROENGINE_LOG_DUMP_HEADER << str << std::endl;
}

macroengine::log::Dump::Dump(std::string const &str) {
  display(str);
}