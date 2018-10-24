/*
** AShape.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/drawable/shape/AShape/AShape.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon Mar 19 11:42:50 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_ASHAPE_HPP
#define MACRO_ENGINE_ASHAPE_HPP

# include				"macroengine-core/utl/types.hpp"
# include				"macroengine-core/Object/Object.hpp"

namespace 				macroengine {
  namespace 				graphics {
    /**
     * \class AShape
     * \brief The abstraction for every Shape of the Macro Engine.
     */
    class				AShape : public Object {
    private:
      t_entity_id 			_id;

    public:
      AShape() = default;
      virtual ~AShape() = default;

      virtual void			dump() override;
    };
  }
}

#endif //MACRO_ENGINE_ASHAPE_HPP
