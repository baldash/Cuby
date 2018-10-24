/*
** StringsFinder.hpp for Macro_Engine in /home/sylvain/Documents/projets/perso/macroengine/macroengine-core/build_utl/strings_finder/StringsFinder/StringsFinder.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed May 30 14:31:58 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_STRINGSFINDER_HPP
#define MACRO_ENGINE_STRINGSFINDER_HPP

# include				<map>
# include				"build_utl.hpp"

namespace				macroengine {
  namespace				build_utl {
    namespace				strings_finder {
      using				t_key = std::pair<std::string, std::string>;
      using				t_strings = std::map<t_key, int>;

      class				StringsFinder {
      private:
        std::string			_original_filename;
        t_strings 			_strings;
        file::File			_strings_builder;
        std::vector<std::string>	_flags;
        size_t				_writing_hook = 0;

      public:
        StringsFinder() = default;
        virtual ~StringsFinder() = default;

	int				initStringBuilder(std::string const &path);
	void				addStrings(const macroengine::build_utl::parser::IniScope::t_ini_scope &scope);
	void				writeStrings();

      private:
        int				countFlags(std::string const &str);
        int				getFlags();
        int				getNextFlag(std::string const &str);
        int				getWritingHook();
      };
    }
  }
}

#endif //MACRO_ENGINE_STRINGSFINDER_HPP
