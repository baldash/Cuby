/*
** CellData.hpp for Macro_Engine in /home/sylvain/Documents/projects/perso/C++/macroengine/macroengine-rpg/map/CellData/CellData.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sat Jun 02 00:39:34 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_RPG_CELLDATA_HPP_
# define MACRO_ENGINE_RPG_CELLDATA_HPP_

# include				<string>
# include				"macroengine-core/parser/ini/IniScope/IniScope.hpp"
# include				"macroengine-rpg/utl/rpg_types.hpp"
# include				"macroengine-core/utl/Dimensions/Dimensions.hpp"

namespace 				macroengine {
  namespace 				rpg {
    namespace 				map {
      class				CellData : public Object {
      public:
	char				flag;
        std::string			name;
        std::string			texture_file;
        utl::Dimensions			dimensions;
        utl::Position			position;
        bool				crossable_by_player = false;
        bool				crossable = false;
        graphics::Sprite		sprite;

        CellData() = default;
        virtual ~CellData() = default;

        void				dump() override;

        int				fromScope(parser::ini::IniScope const &scope, utl::Dimensions const &dim);
      };
    }
  }
}
#endif /* !MACRO_ENGINE_RPG_CELLDATA_HPP_ */
