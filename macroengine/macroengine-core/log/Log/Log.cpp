/*
** Log.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/log/Log/Log.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Jan 24 21:26:37 2018 Sylvain CHAUGNY
*/

#include			<iostream>
#include			"Log.hpp"

void				macroengine::log::Log::display(std::string const &str) {
  std::cout << MACROENGINE_LOG_LOG_HEADER << str << std::endl;
}

macroengine::log::Log::Log(std::string const &str) {
  display(str);
}