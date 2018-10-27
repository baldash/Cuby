/*
** InstallDirectory.cpp for Macro_Engine in /home/sylvain/Documents/projets/perso/macroengine/macroengine-core/build_utl/build_tool/commands/InstallDirectory/InstallDirectory.cpp
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Jul 11 12:03:02 2018 Sylvain Chaugny
*/

#include		"InstallDirectory.hpp"

using namespace		macroengine::build_utl::build_tool;

command::InstallDirectory::InstallDirectory() :
  Command(),
  _install_directory("/usr/local/") {
  setDescription("Sets the installation directory of the libraries (default: " + _install_directory + ")");
  addTrigger("install-directory");
  takesAnArgument(true);
}

int			command::InstallDirectory::onFailure(const std::string &) {
  return _failure_code;
}

int			command::InstallDirectory::onTrigger(const std::string &arg) {
  _install_directory = arg;
  return _success_code;
}

int			command::InstallDirectory::onSuccess(const std::string &) {
  return _success_code;
}

std::string const	&command::InstallDirectory::getInstallDirectory() const {
  return _install_directory;
}
