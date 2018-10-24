/*
** Cell.hpp for Macro_Engine in /home/sylvain/Documents/projects/perso/C++/macroengine/macroengine-rpg/map/Cell/Cell.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon May 21 20:22:34 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_CELL_HPP
#define MACRO_ENGINE_CELL_HPP

# include				"macroengine-rpg/map/CellData/CellData.hpp"
# include				"macroengine-core/macroengine-core.hpp"

namespace 				macroengine {
  namespace 				rpg {
    namespace 				map {
      class				Cell: public Object {
      private:
        CellData			_data;

      public:
        Cell() = default;
	Cell(const CellData &data);
        virtual ~Cell() = default;

	void				dump() override;

	void				init(std::string const &name);
        void				setCellData(const CellData &data, utl::Position const &position, const graphics::Sprite &sprite);
        CellData const			&getCellData() const;

	void				setCellFlag(const char &flag);
      };
    }
  }
}

#endif //MACRO_ENGINE_CELL_HPP
