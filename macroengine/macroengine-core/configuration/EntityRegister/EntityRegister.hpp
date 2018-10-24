/*
** EntityRegister.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/register/EntityRegister/EntityRegister.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Feb 08 10:16:07 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_ENTITYREGISTER_HPP
# define MACRO_ENGINE_ENTITYREGISTER_HPP

# include				"macroengine-core/utl/types.hpp"
# include				"macroengine-core/Object/Object.hpp"

namespace				macroengine {
  namespace 				configuration {

    /**
     * \class EntityRegister
     * \brief Contains the entitied registered by the user in the main, as well as every built entity during the game.
     * This class should not be called by the user (see examples for which macro to use).
     */
    class				EntityRegister : public Object {
    private:
      t_register 			_register;
      t_enabled_at_launch 		_enabled_at_launch;

      t_built_entities			_built_entities;
      t_built_entity 			_null_entity = nullptr;
      t_identifier 			_null_identifier;

    public:
      EntityRegister();
      virtual ~EntityRegister() = default;

      virtual void			dump() override;

      /**
       * initialization method of the class, called by the Configuration configure() method.
       * @return 0 if OK, 1 otherwise
       * @sa Configuration class
       */
      int				configure();

      /**
       * adds an entity to build, specifying the builder and the entity name.
       * @param name the name of the entity
       * @param builder the entity builder (see the examples for more info)
       * @return 0 if ok, 1 otherwise
       */
      int				add(std::string const &name, t_builder builder);


      /**
       * enables an entity at launch.
       * This function doesn't take a t_identifier as parameter because it wouldn't be practical for the user to store data in the main.
       * @param id the entity name
       * @return 0 if OK, 1 otherwise
       */
      int				enableAtLaunch(std::string const &id);

      /**
       * gets a t_build_entity by its identifier (id, name, or both).
       * @param identifier the entity identifier
       * @return a reference on the found t_built_entity. If none is found, returns  a null t_built_entity
       */
      t_built_entity 			&get(t_identifier const &identifier);

      /**
       * build an entity by its identifier (id, name, or both).
       * @param identifier the entity identifier
       * @return 0 is OK, 1 otherwise
       */
      int				build(t_identifier const &identifier);

      /**
       * gets all the built entities.
       * @return a reference on the built entities
       */
      t_built_entities			&getAll();

    private:
      int				build(std::string const &name);
      int				build(t_entity_id const &id);
      int				buildEntities();

      t_built_entity			&get(std::string const &name);
      t_built_entity			&get(t_entity_id const &id);

      t_identifier const		&findRegisteredEntity(t_identifier const &identifier);
      t_identifier const		&findBuiltEntity(t_identifier const &identifier);
    };
  }
}

#endif /* !MACRO_ENGINE_ENTITYREGISTER_HPP */
