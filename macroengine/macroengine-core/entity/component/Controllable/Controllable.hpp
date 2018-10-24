/*
** Controllable.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/component/Controllable/Controllable.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Feb 14 23:43:32 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_COMPONENT_CONTROLLABLE_HPP
#define MACRO_ENGINE_COMPONENT_CONTROLLABLE_HPP

# include				"macroengine-core/controller/event/keyboard/KeyboardData/KeyboardData.hpp"
# include				"macroengine-core/controller/event/mouse/MouseButtonData/MouseButtonData.hpp"
# include				"macroengine-core/controller/event/mouse/MouseMoveData/MouseMoveData.hpp"
# include				"macroengine-core/entity/component/AComponent/AComponent.hpp"
# include				"macroengine-core/entity/AEntity/AEntity.hpp"

namespace				macroengine {
  namespace 				entity {
    namespace 				component {

      /**
       * \class Controllable
       * \brief The Controllable component of the entity. Enabled if the entity is built with property::CONTROLLABLE.
       * This class use mainly used to wrap and access the controller::event classes (see example on how to use them).
       */
      class				Controllable : virtual public AComponent<property::CONTROLLABLE>,
							  virtual protected AEntity,
							  public controller::event::keyboard::KeyboardData<property::CONTROLLABLE>,
							  public controller::event::mouse::MouseMoveData<property::CONTROLLABLE>,
							  public controller::event::mouse::MouseButtonData<property::CONTROLLABLE> {
      public:
	Controllable();
	virtual ~Controllable() = default;
      };
    }
  }
}

#endif //MACRO_ENGINE_COMPONENT_CONTROLLABLE_HPP
