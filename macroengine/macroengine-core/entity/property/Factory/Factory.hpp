/*
** Factory.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/property/Factory/Factory.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Mar 01 10:00:10 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_PROPERTY_FACTORY_HPP
# define MACRO_ENGINE_PROPERTY_FACTORY_HPP

# include				"macroengine-core/entity/Entity/Entity.hpp"
# include				"macroengine-core/entity/property/IProperty/IProperty.hpp"

namespace				macroengine {
  namespace 				property {
    /**
     * \class Factory
     * \brief The Factory class defining the FACTORY property the the inherited Entity central class.
     */
    class				Factory : public IProperty, virtual public entity::Entity {
    public:
      Factory();
      virtual ~Factory() = default;
    };
  }
}

#endif //MACRO_ENGINE_PROPERTY_FACTORY_HPP
