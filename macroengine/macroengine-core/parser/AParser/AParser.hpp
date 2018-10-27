/*
** AParser.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/parser/AParser/AParser.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sat Jan 27 18:40:10 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_APARSER_HPP_
# define MACRO_ENGINE_APARSER_HPP_

# include			"macroengine-core/Object/Object.hpp"
# include			"macroengine-core/parser/IParser/IParser.hpp"

namespace			macroengine {
  namespace			parser {
    /**
     * \class AParser
     * \brief The abstraction of every Macro Engine parser. It provides some useful method to parse the content from different sources.
     */
    class			AParser : public IParser, public Object {
    public:
      AParser();
      virtual ~AParser() = default;

      virtual void		dump() override;

      /**
       * Parses the content of a file::File and stores the parsed data inside the specialized class.
       * The file must already be read (its read() method must have been called before the call to parseFromFile()).
       * @param file the file to parse
       * @return 0 if OK, 1 otherwise
       */
      virtual int		parseFromFile(file::File &file) override = 0;

      /**
       * Parses the given raw content and stores the parsed data inside the specialized class.
       * @param data the raw data of type t_raw_content
       * @return 0 if OK, 1 otherwise
       */
      virtual int		parseFromRawContent(file::t_raw_content const &data) override = 0;
    };
  }
}

#endif /* !MACRO_ENGINE_APARSER_HPP_ */
