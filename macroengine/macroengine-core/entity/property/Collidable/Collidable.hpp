/*
** Collidable.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/property/enum/Collidable/Collidable.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Feb 14 23:13:57 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_PROPERTY_COLLIDABLE_HPP
#define MACRO_ENGINE_PROPERTY_COLLIDABLE_HPP

# include				"macroengine-core/entity/Entity/Entity.hpp"
# include				"macroengine-core/entity/property/IProperty/IProperty.hpp"

namespace				macroengine {
  namespace 				property {

    /**
     * \class Collidable
     * \brief The Collidable class defining the COLLIDABLE property the the inherited Entity central class.
     */
    class				Collidable : public IProperty, virtual public entity::Entity {
    public:
      Collidable();
      virtual ~Collidable() = default;
    };
  }
}

#endif //MACRO_ENGINE_PROPERTY_COLLIDABLE_HPP
