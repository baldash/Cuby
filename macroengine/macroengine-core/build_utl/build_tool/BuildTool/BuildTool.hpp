#ifndef						BUILDTOOL_BUILDTOOL_HPP_
#define						BUILDTOOL_BUILDTOOL_HPP_

# include					"arguments-parser/arguments-parser.hpp"

enum						e_commands {
  HELP						= 1,
  INSTALL,
  INSTALL_DIRECTORY,
  BUILD,
  BUILD_DIRECTORY,
  CLEAN,
  COMMANDS,
};

namespace					macroengine {
  namespace					build_utl {
    namespace					build_tool {
      class					BuildTool {
      private:
	arguments_parser::ArgumentsParser	_parser;
	std::map<int, int>			_commands;
	std::map<int, bool>			_triggers;

      public:
	BuildTool() = default;
	virtual ~BuildTool() = default;

	int					init();
	int					process(const int ac, const char **av);
      };
    }
  }
}

#endif						/* !BUILDTOOL_BUILDTOOL_HPP_ */
