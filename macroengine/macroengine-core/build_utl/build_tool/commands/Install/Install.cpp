#include			<iostream>
#include			"Install.hpp"

using namespace			macroengine::build_utl::build_tool;

command::Install::Install() : Command() {
  setDescription("Installs the library. Enables by default the build argument.");
  takesAnArgument(false);
  addTrigger("install");
  addTrigger('i');
}

int				command::Install::onFailure(std::string const &) {
  return _failure_code;
}

int				command::Install::onSuccess(std::string const &) {
  return _success_code;
}

int				command::Install::onTrigger(std::string const &) {
  return _success_code;
}

int				command::Install::process(std::string const &dir) {
  std::cout << "Installing to " << dir << std::endl;
  return 0;
}
