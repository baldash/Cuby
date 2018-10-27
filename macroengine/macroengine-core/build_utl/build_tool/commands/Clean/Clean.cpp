#include			<iostream>
#include			"Clean.hpp"

using namespace			macroengine::build_utl::build_tool;

command::Clean::Clean() :
  Command(),
  _clean_before(false),
  _clean_after(false) {
  setDescription("Cleans the repository (deletes the build directory and the libraries). Arguments available: 'before|after|both' to clean before, after, of before and after build/install");
  takesAnArgument(true);
  addTrigger("clean");
  addTrigger('c');
}

int				command::Clean::onFailure(std::string const &) {
  return _failure_code;
}

int				command::Clean::onSuccess(std::string const &) {
  return _success_code;
}

int				command::Clean::onTrigger(std::string const &arg) {
  _clean_before = (arg == "before" || arg == "both");
  _clean_after = (arg == "after" || arg == "both");
  return (arg == "before" || arg == "after" || arg == "both") ? _success_code : _failure_code;
}

bool				command::Clean::canCleanBefore() const {
  return _clean_before;
}

bool				command::Clean::canCleanAfter() const {
  return _clean_after;
}

int				command::Clean::cleanBefore() {
  std::cout << "Cleaning before" << std::endl;
  return 0;
}

int				command::Clean::cleanAfter() {
  std::cout << "Cleaning after" << std::endl;
  return 0;
}
