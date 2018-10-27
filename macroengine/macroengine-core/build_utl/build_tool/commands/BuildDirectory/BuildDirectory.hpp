#ifndef				MACROENGINE_BUILDDIRECTORY_HPP_
#define				MACROENGINE_BUILDDIRECTORY_HPP_

# include			"arguments-parser.hpp"

namespace			macroengine {
  namespace			build_utl {
    namespace			build_tool {
      namespace			command {
	class			BuildDirectory : public arguments_parser::Command {
	private:
	  std::string		_build_directory;

	public:
	  BuildDirectory();
	  virtual ~BuildDirectory() = default;

	  int			onFailure(std::string const &arg) override;
	  int			onTrigger(std::string const &str) override;
	  int			onSuccess(std::string const &arg) override;

	  std::string const	&getBuildDirectory() const;
	};
      }
    }
  }
}

#endif			/* !MACROENGINE_BUILDDIRECTORY_HPP_ */
