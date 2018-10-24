/*
** FontEntry.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/text/FontEntry/FontEntry.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Mar 16 10:05:08 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_FONTENTRY_HPP_
# define MACRO_ENGINE_FONTENTRY_HPP_

# include				<string>
# include				<SFML/Graphics/Font.hpp>
# include				"macroengine-core/utl/types.hpp"

namespace				macroengine {
  namespace 				graphics {
    namespace 				utl {
      /**
       * \struct FontEntry
       * \brief Container providing data for a user-created font.
       */
      struct				FontEntry {
	std::string			path;
	std::string			name;
	sf::Font			font;
	t_entity_id 			id = 0;
      };
    }
  }
}

#endif /* !MACRO_ENGINE_FONTENTRY_HPP_ */
