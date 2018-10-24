/*
** IParser.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/parser/IParser/IParser.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sat Jan 27 18:41:05 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_IPARSER_HPP_
# define MACRO_ENGINE_IPARSER_HPP_

# include			"macroengine-core/file/File/File.hpp"

namespace			macroengine {
  namespace			parser {
    /**
     * \class IParser
     * \brief The interface for the macroengine::parser::AParser class.
     */
    class			IParser {
    public:
      virtual ~IParser() = default;

      virtual int		parseFromFile(file::File &file) = 0;
      virtual int		parseFromRawContent(file::t_raw_content const &file) = 0;
    };
  }
}

#endif /* !MACRO_ENGINE_IPARSER_HPP_ */
