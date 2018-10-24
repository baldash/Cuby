/*
** Environment.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/core/configuration/Environment/Environment.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Tue Feb 13 23:21:52 2018 Sylvain CHAUGNY
*/

# include					"macroengine-core/log/log.hpp"
#include					"Environment.hpp"
# include					"macroengine-core/utl/macros/macros_definitions.hpp"

macroengine::configuration::Environment::Environment() :
  Object("Environment") {
}

void						macroengine::configuration::Environment::set(int ac, char **av, char **ae) {
  _ac = ac;
  _av = av;
  _ae = ae;
}

void						macroengine::configuration::Environment::dump() {
}

int						macroengine::configuration::Environment::configure() {
  _resources_directory = MACROENGINE_VAR_DEFAULT_RESOURCES_DIRECTORY;
  return 0;
}

const macroengine::configuration::Environment	&macroengine::configuration::Environment::getAsConst() {
  return *this;
}

std::string const 				&macroengine::configuration::Environment::getResourcesDirectory() const {
  return _resources_directory;
}
