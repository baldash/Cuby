/*
** AComponent.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/component/AComponent/AComponent.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Feb 15 00:48:13 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_ACOMPONENT_HPP
#define MACRO_ENGINE_ACOMPONENT_HPP

# include					"macroengine-core/entity/property/enum/e_property.hpp"
# include					"macroengine-core/clock/Clock/Clock.hpp"

namespace 					macroengine {
  namespace 					entity {
    namespace 					component {

      /**
       * \class AComponent
       * \brief An abstraction for all the Entity components.
       * @tparam Type the property::e_property value of the component
       */
      template<property::e_property Type>
      class					AComponent {
      private:
	clock::t_delay_id 			_const_delay;
	bool					_use_const_delay;

      public:
	AComponent() :
	  _use_const_delay(false) {
	}

	virtual ~AComponent() = default;

	/**
	 * [UNUSED METHOD]
	 * Checks whether the component is using a constant delay.
	 * @return true if the component is, false otherwise
	 */
	bool					isUsingConstDelay() {
	  return _use_const_delay;
	}

	/**
	 * [UNUSED METHOD]
	 * Defines if the entity is using a constant delay.
	 * @param use true if the user wants to use a constant delay, false otherwise
	 */
	void					useConstDelay(bool use) {
	  _use_const_delay = use;
	}

	/**
	 * [UNUSED METHOD]
	 * Gets the constant delay of the entity.
	 * @return the t_delay_id
	 */
	clock::t_delay_id 			getConstDelay() {
	  return _const_delay;
	}

	/**
	 * [UNUSED METHOD]
	 * Sets the constant delay.
	 * @param id the t_delay_id
	 */
	void					setConstDelay(clock::t_delay_id id) {
	  _const_delay = id;
	}
      };
    }
  }
}

#endif //MACRO_ENGINE_ACOMPONENT_HPP
