/*
** TextEntry.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/TextEntry/TextEntry.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Mar 15 16:42:45 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_TEXTENTRY_HPP_
# define MACRO_ENGINE_TEXTENTRY_HPP_

# include				<SFML/Graphics/Text.hpp>
# include				<string>
# include				"macroengine-core/utl/Position/Position.hpp"
# include				"macroengine-core/utl/types.hpp"

namespace				macroengine {
  namespace 				graphics {
    namespace 				utl {
      /**
       * \struct TextEntry
       * \brief Container providing data for a user-created text.
       */
      struct				TextEntry {
	std::string			string;
	sf::Text			text;
	macroengine::utl::Position	position = {0, 0};
	std::string			name;
	int				size = 12;
	t_entity_id 			id = 0;
      };
    }
  }
}

#endif /* !MACRO_ENGINE_TEXTENTRY_HPP_ */
