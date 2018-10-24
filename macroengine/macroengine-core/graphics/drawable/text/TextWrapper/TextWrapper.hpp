//
// TextWrapper.hpp for macroengine in /home/sylvain/Documents/projets/perso/macroengine
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Wed Apr 25 15:04:02 2018 Sylvain Chaugny
// Last update Wed Apr 25 15:04:02 2018 Sylvain Chaugny
//

#ifndef	MACROENGINE_TEXTWRAPPER_HPP_
#define MACROENGINE_TEXTWRAPPER_HPP_

# include				<map>
# include				"macroengine-core/graphics/drawable/ADrawableHandler/ADrawableHandler.hpp"
# include				"macroengine-core/graphics/drawable/text/Text/Text.hpp"

namespace				macroengine {
  namespace				graphics {
    /**
     * \class TextWrapper
     * \brief This class is used to handle multiple texts and provides a container to store every known text for the created entity.
     */
    class				TextWrapper : public ADrawableHandler {
    private:
      t_texts				_texts;

    public:
      TextWrapper() = default;
      virtual ~TextWrapper() = default;

      /**
       * Adds a text from a ini file.
       * @param name the text name
       * @param path the file path
       * @return a reference on the new Text
       */
      Text				&addFromIni(std::string const &name, std::string const &path);

      /**
       * Gets a Text given its identifier (id, name or both).
       * If no item matches, it throws a exception::UnknownTextIDException or a exception::UnknownTextNameException depending on the identifier content.
       * @param identifier the identifier
       * @return a reference on the found Text
       */
      Text				&get(t_identifier const &identifier);

    private:
      Text				&get(std::string const &name);
      Text				&get(t_entity_id const &id);
    };
  }
}


#endif /* !MACROENGINE_TEXTWRAPPER_HPP_ */
