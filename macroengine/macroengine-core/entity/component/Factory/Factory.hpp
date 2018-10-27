/*
** Factory.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/component/Factory/Factory.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Mar 01 10:03:02 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_COMPONENT_FACTORY_HPP
#define MACRO_ENGINE_COMPONENT_FACTORY_HPP

# include					"macroengine-core/entity/component/AComponent/AComponent.hpp"
# include					"macroengine-core/entity/AEntity/AEntity.hpp"

namespace					macroengine {
  namespace 					entity {
    namespace 					component {

      /**
       * \class Factory
       * \brief The Factory component of the entity. Enabled if the entity is built with property::FACTORY.
       * This class is used to invoke new entities at runtime. The user must override the invoke() method to do so (see examples).
       */
      class					Factory : virtual public AComponent<property::FACTORY>, virtual protected AEntity {
      private:
	configuration::t_built_entities 	_created_entities;
	t_identifier 				_null_identifier;

      public:
	Factory() = default;
	virtual ~Factory() = default;

	/**
	 * The invoke() method to override. It must call the addEntity() method to create a new entity and put it in the local t_built_entities instance.
	 * @param str the entity name
	 */
	virtual entity::Entity			&invoke(std::string const &str);

	/**
	 * Adds an entity to the t_built_entities instance.
	 * @param str the entity name
	 * @param ent a pointer on the created entity
	 * @return the created entity
	 */
	entity::Entity				&addEntity(std::string const &str, entity::Entity *ent);

	/**
	 * Gets the created entities.
	 * @return a reference on the t_built_entities array
	 */
	configuration::t_built_entities 	&getCreatedEntities();

      private:
        t_identifier const			&findCreatedEntity(t_identifier const &identifier);
      };
    }
  }
}

#endif //MACRO_ENGINE_COMPONENT_FACTORY_HPP
