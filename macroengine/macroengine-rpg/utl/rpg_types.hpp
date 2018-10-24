/*
** types.hpp for Macro_Engine in /home/sylvain/Documents/projects/perso/C++/macroengine/macroengine-rpg/utl/types.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sat Jun 02 00:17:29 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_RPG_TYPES_HPP_
# define MACRO_ENGINE_RPG_TYPES_HPP_

# include				<vector>
# include				<string>
# include				<memory>
# include				<unordered_map>
# include				"macroengine-core/utl/Position/Position.hpp"
# include				"macroengine-core/graphics/drawable/sprite/Sprite/Sprite.hpp"

namespace 				macroengine {
  namespace 				rpg {

    namespace 				map {
      class				Cell;
      struct				CellData;
    }

    namespace				map {
      using				t_shared_sprite = std::shared_ptr<graphics::Sprite>;
    }

    using				t_raw_map = std::vector<std::string>;
    using				t_cells = std::unordered_map<macroengine::utl::Position, map::Cell>;
    using				t_cell_dictionary = std::unordered_map<char, map::CellData>;

    namespace				character {
      using				t_stored_entities = std::map<std::string, t_identifier>;
    }
  }
}

#endif /* !MACRO_ENGINE_RPG_TYPES_HPP_ */
