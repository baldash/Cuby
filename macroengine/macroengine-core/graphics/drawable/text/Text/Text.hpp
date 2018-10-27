/*
** Text.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/Text/Text.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sat Mar 10 22:42:58 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_TEXT_HPP
#define MACRO_ENGINE_TEXT_HPP

# include				"macroengine-core/graphics/drawable/ADrawableHandler/ADrawableHandler.hpp"
# include				"macroengine-core/parser/ini/IniParser/IniParser.hpp"
# include				"macroengine-core/graphics/utl/FontEntry/FontEntry.hpp"
# include				"macroengine-core/graphics/utl/TextEntry/TextEntry.hpp"
# include				"macroengine-core/utl/types.hpp"
# include				"macroengine-core/Object/Object.hpp"

namespace 				macroengine {
  namespace 				graphics {
    /**
     * \class Text
     * \brief The sf::Text wrapper, allowing the user to create Macro Engine compatible text.
     * See the examples on how to handle this class.
     */
    class				Text : public ADrawableHandler, public Object {
    private:
      utl::TextEntry			_empty_text;
      t_text_entries 			_text_entries;
      t_font_entries 			_font_entries;

    public:
      Text();
      virtual ~Text() = default;

      virtual void			dump() override;

      /**
       * Loads a text from a configuration file (see examples).
       * @param file the file path
       * @return 0 if OK, 1 otherwise
       */
      int				loadFromIni(std::string const &file);

      /**
       * Gets the created text entries.
       * @return a t_text_entries reference.
       */
      t_text_entries 			&getEntries();

      utl::TextEntry			&get(std::string const &name);
      utl::TextEntry			&get(t_entity_id const &id);

    private:
      t_entity_id 			getFontFromIni(parser::ini::IniParser &parser, std::string const &);
      int				getTextEntriesFromIni(parser::ini::IniParser &parser, std::string const &path, t_entity_id font_id);
      t_entity_id 			getTextEntryFromLine(std::pair<std::string, std::string> const  &entry, parser::ini::IniParser &parser, t_entity_id font_id);
    };
  }
}

#endif //MACRO_ENGINE_TEXT_HPP
