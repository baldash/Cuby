/*
** Animable.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/property/enum/Animable/Animable.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Feb 14 23:13:57 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_PROPERTY_SCRIPTABLE_HPP
#define MACRO_ENGINE_PROPERTY_SCRIPTABLE_HPP

# include				"macroengine-core/entity/Entity/Entity.hpp"
# include				"macroengine-core/entity/property/IProperty/IProperty.hpp"

namespace				macroengine {
  namespace 				property {

    /**
     * \class Scriptable
     * \brief The Scriptable class defining the SCRIPTABLE property the the inherited Entity central class.
     */
    class				Scriptable : public IProperty, virtual public entity::Entity {
    public:
      Scriptable();
      virtual ~Scriptable() = default;
    };
  }
}

#endif //MACRO_ENGINE_PROPERTY_SCRIPTABLE_HPP
