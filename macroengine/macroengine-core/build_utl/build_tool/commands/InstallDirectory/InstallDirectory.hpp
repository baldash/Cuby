#ifndef				MACROENGINE_INSTALLDIRECTORY_HPP_
#define				MACROENGINE_INSTALLDIRECTORY_HPP_

# include			"arguments-parser.hpp"

namespace			macroengine {
  namespace			build_utl {
    namespace			build_tool {
      namespace			command {
	class			InstallDirectory : public arguments_parser::Command {
	private:
	  std::string		_install_directory;

	public:
	  InstallDirectory();
	  virtual ~InstallDirectory() = default;

	  int			onFailure(std::string const &arg) override;
	  int			onTrigger(std::string const &str) override;
	  int			onSuccess(std::string const &arg) override;

	  std::string const	&getInstallDirectory() const;
	};
      }
    }
  }
}

#endif			/* !MACROENGINE_INSTALLDIRECTORY_HPP_ */
