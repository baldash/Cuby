/*
** AEntity.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/AEntity/AEntity.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Feb 14 23:45:34 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_AENTITY_HPP
#define MACRO_ENGINE_AENTITY_HPP

# include				<map>
# include				"macroengine-core/utl/types.hpp"
# include				"macroengine-core/entity/IEntity/IEntity.hpp"
# include				"macroengine-core/Object/Object.hpp"
# include				"macroengine-core/utl/BitMask/BitMask.hpp"
# include				"macroengine-core/entity/property/enum/e_property.hpp"

namespace 				macroengine {
  namespace 				entity {

    /**
     * \class AEntity
     * \brief An abstraction for the Entity class.
     * It provides an implementation of the IEntity class and the subproperties system (see Entity-related examples).
     * This method should not be used by the user, see the macros and the Entity-related examples.
     */
    class				AEntity : public Object, public IEntity {
    private:
      utl::BitMask			_properties_mask;
      t_subproperties 			_subproperties;

    public:
      AEntity();
      virtual ~AEntity() = default;

      virtual void			dump() override;

      /**
       * Gets the bitmask of the the entity properties.
       * @return a reference on the bitmask
       */
      utl::BitMask			&getMask() override;

      /**
       * Gets the entity subproperties.
       * @return the instance of the t_subproperties array
       */
      t_subproperties 			&getSubProperties() override;

      /**
       * Adds a property to the entity.
       * @param property a property::e_property value
       */
      void				addProperty(property::e_property property) override;

      /**
       * Sets the subproperty bitmask of a given property, overriding previously defined subproperties for this property.
       * @param prop the property
       * @param sub the bitmask
       */
      void				addSubProperties(property::e_property prop, utl::BitMask const &sub) override;

      /**
       * Adds a subproperty to a given property.
       * @param prop the given property::e_property
       * @param sub the property::e_subproperty to add
       */
      void				addSubProperty(property::e_property prop, property::e_subproperty sub) override;
//
//      t_identifier const		&getIdentifier() const;
//      void				setIdentifier(t_identifier const &identifier);
    };
  }
}

#endif //MACRO_ENGINE_AENTITY_HPP
