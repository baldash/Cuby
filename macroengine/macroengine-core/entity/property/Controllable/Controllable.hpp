/*
** Controllable.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/property/enum/Controllable/Controllable.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Feb 14 23:13:57 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_PROPERTY_CONTROLLABLE_HPP
#define MACRO_ENGINE_PROPERTY_CONTROLLABLE_HPP

# include				"macroengine-core/entity/Entity/Entity.hpp"
# include				"macroengine-core/entity/property/IProperty/IProperty.hpp"

namespace				macroengine {
  namespace 				property {

    /**
     * \class Controllable
     * \brief The Controllable class defining the CONTROLLABLE property the the inherited Entity central class.
     */
    class				Controllable : public IProperty, virtual public entity::Entity {
    public:
      Controllable();
      virtual ~Controllable() = default;
    };
  }
}

#endif //MACRO_ENGINE_PROPERTY_CONTROLLABLE_HPP
