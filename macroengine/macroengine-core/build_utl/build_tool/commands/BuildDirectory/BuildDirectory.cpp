/*
** BuildDirectory.cpp for Macro_Engine in /home/sylvain/Documents/projets/perso/macroengine/macroengine-core/build_utl/build_tool/commands/BuildDirectory/BuildDirectory.cpp
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Jul 11 12:03:02 2018 Sylvain Chaugny
*/

#include		"BuildDirectory.hpp"

using namespace		macroengine::build_utl::build_tool;

command::BuildDirectory::BuildDirectory() :
  Command(),
  _build_directory("./.lib") {
  setDescription("Sets the building directory of the libraries (default: " + _build_directory + ")");
  addTrigger("build-directory");
  takesAnArgument(true);
}

int			command::BuildDirectory::onFailure(const std::string &) {
  return _failure_code;
}

int			command::BuildDirectory::onTrigger(const std::string &arg) {
  _build_directory = arg;
  return _success_code;
}

int			command::BuildDirectory::onSuccess(const std::string &) {
  return _success_code;
}

std::string const	&command::BuildDirectory::getBuildDirectory() const {
  return _build_directory;
}
