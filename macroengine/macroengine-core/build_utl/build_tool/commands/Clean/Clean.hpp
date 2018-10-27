#ifndef				MACROENGINE_CLEAN_HPP_
#define				MACROENGINE_CLEAN_HPP_

# include			"arguments-parser.hpp"

namespace			macroengine {
  namespace			build_utl {
    namespace			build_tool {
      namespace			command {
	class			Clean : public arguments_parser::Command {
	public:
	  enum			e_method {
	    BEFORE,
	    AFTER,
	  };

	private:
	  bool			_clean_before;
	  bool			_clean_after;

	public:
	  Clean();
	  virtual ~Clean() = default;

	  int			onFailure(std::string const &arg) override;
	  int			onTrigger(std::string const &str) override;
	  int			onSuccess(std::string const &arg) override;

	  bool			canCleanBefore() const;
	  bool			canCleanAfter() const;

	  int			cleanBefore();
	  int			cleanAfter();
	};
      }
    }
  }
}

#endif			/* !MACROENGINE_CLEAN_HPP_ */
