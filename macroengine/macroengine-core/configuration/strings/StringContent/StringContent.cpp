/*
** StringContent.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/utl/strings/StringContent/StringContent.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Feb 15 19:45:25 2018 Sylvain CHAUGNY
*/

#include			"StringContent.hpp"

macroengine::configuration::strings::StringContent::StringContent() :
  str(""),
  nb_params(0) {
}

macroengine::configuration::strings::StringContent::StringContent(std::string const &_str, int _nb_params) :
  str(_str),
  nb_params(_nb_params) {
}
