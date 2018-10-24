/*
** IEntity.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/IEntity/IEntity.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Feb 15 00:18:30 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_IENTITY_HPP_
# define MACRO_ENGINE_IENTITY_HPP_

# include				"macroengine-core/utl/BitMask/BitMask.hpp"
# include				"macroengine-core/utl/types.hpp"
# include				"macroengine-core/entity/property/enum/e_property.hpp"
# include				"macroengine-core/entity/property/enum/e_subproperty.hpp"

namespace 				macroengine {
  namespace 				entity {

    /**
     * \class IEntity
     * \brief the Interface for the AEntity class. Implements the bitmask and properties methods.
     */
    class				IEntity {
    public:
      virtual ~IEntity() = default;

      virtual void			dump() = 0;

      virtual utl::BitMask		&getMask() = 0;
      virtual t_subproperties 		&getSubProperties() = 0;
      virtual void			addProperty(property::e_property property) = 0;
      virtual void			addSubProperty(property::e_property prop, property::e_subproperty sub) = 0;
      virtual void			addSubProperties(property::e_property prop, utl::BitMask const &sub) = 0;
    };
  }
}
#endif /* !MACRO_ENGINE_IENTITY_HPP_ */
