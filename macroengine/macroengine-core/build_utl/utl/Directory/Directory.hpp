/*
** Directory.hpp for Macro_Engine in /home/sylvain/Documents/projets/perso/macroengine/macroengine-core/build_utl/strings_finder/Directory/Directory.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Tue May 29 10:35:15 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_RPG_DIRECTORY_HPP
#define MACRO_ENGINE_RPG_DIRECTORY_HPP

# include				<string>
# include				<vector>

namespace				macroengine {
  namespace				build_utl {
    class				Directory {
    private:
      std::string			_root_path;

    public:
      Directory() = default;
      Directory(std::string const &root);

      virtual ~Directory() = default;

      void				setRootPath(std::string const &path);
      std::string const			&getRootPath();

      bool				contains(std::string const &pattern);

      std::vector<std::string>		findMatchingStart(std::string const &start);

    };
  }
}

#endif //MACRO_ENGINE_RPG_DIRECTORY_HPP
