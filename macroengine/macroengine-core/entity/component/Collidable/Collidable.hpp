/*
** Collidable.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/component/Collidable/Collidable.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Feb 14 23:43:32 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_COMPONENT_COLLIDABLE_HPP
#define MACRO_ENGINE_COMPONENT_COLLIDABLE_HPP

# include				"macroengine-core/entity/component/AComponent/AComponent.hpp"
# include				"macroengine-core/entity/AEntity/AEntity.hpp"

namespace				macroengine {
  namespace 				entity {
    namespace 				component {

      /**
       * \class Collidable
       * \brief [UNUSED] The Collidable component of the entity. Enabled if the entity is built with property::COLLIDABLE.
       */
      class				Collidable : virtual public AComponent<property::COLLIDABLE>, virtual protected AEntity {
      public:
	Collidable();
	virtual ~Collidable() = default;
      };
    }
  }
}

#endif //MACRO_ENGINE_COMPONENT_COLLIDABLE_HPP
