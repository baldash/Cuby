/*
** File.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/file/File/File.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Jan 26 15:35:48 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_FILE_HPP_
# define MACRO_ENGINE_FILE_HPP_

# include				<fstream>
# include				"macroengine-core/build_utl/utl/IniParser/IniParser.hpp"

namespace 				macroengine {
  namespace				build_utl {
    namespace				file {
      class				File {
      private:
	std::string			_filename;
	parser::t_raw_content		_content;
	std::ifstream			_stream;

      public:
	File(std::string const &file = "");
	~File() = default;

	void				open();
	void				close();
	bool				good() const;
	int				read();
	parser::t_raw_content const	&getContent() const;
	void				setFileName(std::string const &file);
	std::string const		&getFileName() const;
	void				reset();
      };
    };
  };
};

#endif /* !MACRO_ENGINE_FILE_HPP_ */
