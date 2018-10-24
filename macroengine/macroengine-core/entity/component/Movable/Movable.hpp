/*
** Movable.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/component/Movable/Movable.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Feb 14 23:43:32 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_COMPONENT_MOVABLE_HPP
#define MACRO_ENGINE_COMPONENT_MOVABLE_HPP

# include				"macroengine-core/utl/Position/Position.hpp"
# include				"macroengine-core/utl/vector/VectorF/VectorF.hpp"
# include				"macroengine-core/entity/component/AComponent/AComponent.hpp"
# include				"macroengine-core/entity/AEntity/AEntity.hpp"

namespace				macroengine {
  namespace 				entity {
    namespace 				component {
      /**
       * \class Movable
       * \brief The Movable component of the entity. Enabled if the entity is built with property::MOVABLE.
       */
      class				Movable : virtual public AComponent<property::MOVABLE>, virtual protected AEntity {
      private:
	utl::VectorF			_movement;
	utl::Position			_position;
	bool				_enabled;
	utl::BitMask			_enabled_for_drawable_subproperty;

      public:
	Movable();
	virtual ~Movable() = default;

	void				setMovementFrequency(clock::Time const &t);
	void				setMovement(utl::VectorF const &v);
	utl::VectorF const		&getMovement();

	void				setRawPosition(utl::Position const &);
	void				setRawPosition(size_t x, size_t y);
	utl::Position			&getRawPosition();

	void				enableSelfMovement();
	void				disableSelfMovement();
	bool				isSelfMovementEnabled();
	void				allowSelfMovementForDrawableSubProperty(property::e_subproperty prop);
	void				allowSelfMovementForAllDrawableSubProperties();
	bool				isAllowedForDrawableSubProperty(property::e_subproperty prop);
      };
    }
  }
}

#endif //MACRO_ENGINE_COMPONENT_MOVABLE_HPP
