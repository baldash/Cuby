#ifndef				MACROENGINE_INSTALL_HPP_
#define				MACROENGINE_INSTALL_HPP_

# include			"arguments-parser.hpp"

namespace			macroengine {
  namespace			build_utl {
    namespace			build_tool {
      namespace			command {
	class			Install : public arguments_parser::Command {
	public:
	  Install();
	  virtual ~Install() = default;

	  int			onFailure(std::string const &arg) override;
	  int			onTrigger(std::string const &str) override;
	  int			onSuccess(std::string const &arg) override;

	  int			process(std::string const &dir);
	};
      }
    }
  }
}

#endif			/* !MACROENGINE_INSTALL_HPP_ */
