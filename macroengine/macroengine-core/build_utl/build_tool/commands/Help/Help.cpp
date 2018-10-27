#include			"Help.hpp"
using namespace			macroengine::build_utl::build_tool;

command::Help::Help() {
  setDescription("Displays help and exits");
  addTrigger("help");
  addTrigger('h');
  stopsOnSuccess(true);
  stopsOnFailure(true);
  takesAnArgument(false);
  setFailureCode(1);
  setSuccessCode(0);
}

int				command::Help::onTrigger(std::string const &) {
  displayHelp();
  return _success_code;
}

int				command::Help::onFailure(std::string const &) {
  displayHelp();
  return _failure_code;
}

int				command::Help::onSuccess(std::string const &) {
  return _success_code;
}

void				command::Help::setExecutableName(std::string const &name) {
  _executable_name = name;
}

void				command::Help::displayHelp() {
  size_t			padding;

  padding = getSpacePadding();
  std::cout << "Usage: " << _executable_name << " [ARGS...]" << std::endl;
  std::cout << "Parameters:" << std::endl;
  for (auto &&desc: _commands_descriptions) {
    std::cout << "  " << desc.first << std::string(padding - desc.first.length() + 1, ' ') << ": " << desc.second << std::endl;
  }
}

void				command::Help::addCommandHelp(Command &cmd) {
  _commands_descriptions[parseTriggers(cmd.getTriggers(), cmd.takesAnArgument())] = cmd.getDescription();
}

size_t				command::Help::getSpacePadding() {
  size_t			padding = 0;

  for (auto &&desc: _commands_descriptions) {
    if (desc.first.length() > padding) {
      padding = desc.first.length();
    }
  }
  return padding;
}

std::string			command::Help::parseTriggers(std::vector<std::string> const &triggers, bool arg) {
  std::string			str;

  for (size_t i = 0; i < triggers.size(); i++) {
    if (triggers[i].length() == 1) {
      str += "-" + triggers[i] + (arg ? " [ARG]" : "");
    } else {
      str += "--" + triggers[i] + (arg ? "=[ARG]" : "");
    }
    if (i + 1 != triggers.size()) {
      str += " | ";
    }
  }
  return str;
}
