/*
** Scriptable.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/Scriptable/Scriptable.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Feb 15 00:01:35 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_COMPONENT_SCRIPTABLE_HPP
#define MACRO_ENGINE_COMPONENT_SCRIPTABLE_HPP

# include				"macroengine-core/entity/property/enum/e_property.hpp"
# include				"macroengine-core/entity/component/AComponent/AComponent.hpp"
# include				"macroengine-core/entity/AEntity/AEntity.hpp"
# include				"macroengine-core/entity/component/utl/ScriptableCallableParams/ScriptableCallableParams.hpp"

namespace				macroengine {
  namespace 				entity {
    namespace 				component {

      /**
       * \class Scriptable
       * \brief The Scriptable component of the entity. Enabled if the entity is built with property::SCRIPTABLE.
       */

      class				Scriptable : virtual public AComponent<property::SCRIPTABLE>, virtual protected AEntity {
      private:
	t_callables 			_callables;

      public:
	Scriptable();
	virtual ~Scriptable() = default;

	/**
	 * Adds a timed callable.
	 * @param name the callable name
	 * @param callable the t_callable generated with the makeCallable() macro
	 * @param time the delay time between each call to the callable
	 * @return a reference on the created callable params
	 */
	ScriptableCallableParams	&addTimedCallable(std::string const &name, controller::t_callable callable, clock::Time const &time);

	/**
	 * Adds a timed callable.
	 * @param name the callable name
	 * @param callable the t_callable generated with the makeCallable() macro
	 * @param id the delay id retrieved from a call to CoreClock.newDelay()
	 * @return a reference on the created callable params
	 */
	ScriptableCallableParams	&addTimedCallable(std::string const &name, controller::t_callable callable, clock::t_delay_id id);

	/**
	 * Gets the created callables.
	 * @return a reference on the t_callables instance
	 */
	t_callables 			&getCallables();

	/**
	 * Removes a callable given its identifier (name, id or both).
	 * @param identifier the callable identifier
	 */
	void				removeCallable(t_identifier const &identifier);

      private:
	void				removeCallable(t_entity_id const &id);
	void				removeCallable(std::string const &name);
      };
    }
  }
}

#endif //MACRO_ENGINE_COMPONENT_SCRIPTABLE_HPP
