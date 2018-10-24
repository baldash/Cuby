#ifndef						MACROENGINE_HELP_HPP_
#define						MACROENGINE_HELP_HPP_

# include					"arguments-parser.hpp"

namespace					macroengine {
  namespace					build_utl {
    namespace					build_tool {
      namespace					command {
	class					Help : public arguments_parser::Command {
	private:
	  std::map<std::string, std::string>	_commands_descriptions;
	  std::string				_executable_name;

	public:
	  Help();
	  virtual ~Help() = default;

	  int					onFailure(std::string const &arg) override;
	  int					onTrigger(std::string const &str) override;
	  int					onSuccess(std::string const &arg) override;

	  void					setExecutableName(std::string const &name);

	  void					displayHelp();
	  void					addCommandHelp(Command &cmd);
	  size_t				getSpacePadding();

	  std::string				parseTriggers(std::vector<std::string> const &triggers, bool arg);
	};
      }
    }
  }
}

#endif					/* !MACROENGINE_HELP_HPP_ */
