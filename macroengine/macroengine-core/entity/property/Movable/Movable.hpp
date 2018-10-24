/*
** Movable.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/property/enum/Movable/Movable.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Feb 14 23:13:57 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_PROPERTY_MOVABLE_HPP
#define MACRO_ENGINE_PROPERTY_MOVABLE_HPP

# include				"macroengine-core/entity/Entity/Entity.hpp"
# include				"macroengine-core/entity/property/IProperty/IProperty.hpp"

namespace				macroengine {
  namespace 				property {

    /**
     * \class Movable
     * \brief The Movable class defining the MOVABLE property the the inherited Entity central class.
     */
    class				Movable : public IProperty, virtual public entity::Entity {
    public:
      Movable();
      virtual ~Movable() = default;
    };
  }
}

#endif //MACRO_ENGINE_PROPERTY_MOVABLE_HPP
