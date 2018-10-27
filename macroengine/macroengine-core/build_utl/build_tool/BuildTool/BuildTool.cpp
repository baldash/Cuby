#include		<iostream>
#include		"commands/commands.hpp"
#include		"BuildTool.hpp"

using namespace		macroengine::build_utl::build_tool;

int			BuildTool::init() {
  _commands[e_commands::HELP] = _parser.addDefaultCommand<command::Help>();
  _commands[e_commands::INSTALL] = _parser.addCommand<command::Install>();
  _commands[e_commands::INSTALL_DIRECTORY] = _parser.addCommand<command::InstallDirectory>();
  _commands[e_commands::BUILD] = _parser.addCommand<command::Build>();
  _commands[e_commands::BUILD_DIRECTORY] = _parser.addCommand<command::BuildDirectory>();
  _commands[e_commands::CLEAN] = _parser.addCommand<command::Clean>();

  _parser.getDefaultCommand<command::Help>().addCommandHelp(_parser.getCommand<command::Help>(_commands[e_commands::HELP]));
  _parser.getDefaultCommand<command::Help>().addCommandHelp(_parser.getCommand<command::Install>(_commands[e_commands::INSTALL]));
  _parser.getDefaultCommand<command::Help>().addCommandHelp(_parser.getCommand<command::InstallDirectory>(_commands[e_commands::INSTALL_DIRECTORY]));
  _parser.getDefaultCommand<command::Help>().addCommandHelp(_parser.getCommand<command::Build>(_commands[e_commands::BUILD]));
  _parser.getDefaultCommand<command::Help>().addCommandHelp(_parser.getCommand<command::BuildDirectory>(_commands[e_commands::BUILD_DIRECTORY]));
  _parser.getDefaultCommand<command::Help>().addCommandHelp(_parser.getCommand<command::Clean>(_commands[e_commands::CLEAN]));
  return 0;
}

int			BuildTool::process(const int ac, const char **av) {
  _parser.getDefaultCommand<command::Help>().setExecutableName(av[0]);
  _parser.needsAtLeastOneArgument(true);
  if (_parser.parse(ac, av, 1) || _parser.getDefaultCommand().hasBeenTriggered()) {
    return 1;
  }
  for (int i = 0; i < e_commands::COMMANDS; i++) {
    _triggers[i] = _parser.getCommand(_commands[i]).hasBeenTriggered();
  }

  if (_triggers[e_commands::CLEAN] && _parser.getCommand<command::Clean>(_commands[e_commands::CLEAN]).canCleanBefore()) {
    _parser.getCommand<command::Clean>(_commands[e_commands::CLEAN]).cleanBefore();
  }

  if (_triggers[e_commands::INSTALL] || _triggers[e_commands::BUILD]) {
    _parser.getCommand<command::Build>(_commands[e_commands::BUILD]).process(_parser.getCommand<command::BuildDirectory>(_commands[e_commands::BUILD_DIRECTORY]).getBuildDirectory());
  }
  if (_triggers[e_commands::INSTALL]) {
    _parser.getCommand<command::Install>(_commands[e_commands::INSTALL]).process(_parser.getCommand<command::InstallDirectory>(_commands[e_commands::INSTALL_DIRECTORY]).getInstallDirectory());
  }

  if (_triggers[e_commands::CLEAN] && _parser.getCommand<command::Clean>(_commands[e_commands::CLEAN]).canCleanAfter()) {
    _parser.getCommand<command::Clean>(_commands[e_commands::CLEAN]).cleanAfter();
  }
  return 0;
}
