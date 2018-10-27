/*
** find_entity.hpp for Macro_Engine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/configuration/static/find_entity.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun May 06 23:12:38 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_FIND_ENTITY_HPP_
# define MACRO_ENGINE_FIND_ENTITY_HPP_

# include			"macroengine-core/utl/strings.hpp"
# include			"macroengine-core/utl/exceptions.hpp"
# include			"macroengine-core/utl/types.hpp"

namespace 			macroengine {
  /**
   * \class FindEntity
   * \brief contains a set of find_entity functions, each of them returning a reference on a entity::Entity class.
   * This entity::Entity class is found from a t_built_entities array.
   * These functions should be accessed by the findEntity macro.
   * If no entity matches, a exception::UnknownEntityIDException/NameException is raised.
   */
  class				FindEntity {
  public:
    template<typename Type>
    static Type			&find_entity(configuration::t_built_entities &entities, std::string const &name) {
      Type			*ptr;

      for (auto &&entity: entities) {
	if (entity.first.name == name) {
	   ptr = dynamic_cast<Type *>(entity.second.get());
	  if (ptr != nullptr) {
	    return *ptr;
	  }
	}
      }
      throw exception::UnknownEntityNameException(Strings("core_unknown_entity_name", name));
    }

    template<typename Type>
    static Type			&find_entity(configuration::t_built_entities &entities, t_entity_id const &id) {
      Type			*ptr;

      for (auto &&entity: entities) {
	if (entity.first.id == id) {
	  ptr = dynamic_cast<Type *>(entity.second.get());
	  if (ptr != nullptr) {
	    return *ptr;
	  }
	}
      }
      throw exception::UnknownEntityIDException(Strings("core_unknown_entity_id", id));
    }

    template<typename Type>
    static Type			&find_entity(configuration::t_built_entities &entities, t_identifier const &identifier) {
      Type			*ptr;

      if (identifier.filled()) {
        if (entities.find(identifier) != entities.end()) {
	  ptr = dynamic_cast<Type *>(entities.find(identifier)->second.get());
	  if (ptr != nullptr) {
	    return *ptr;
	  }
        }
	throw exception::UnknownEntityIDException(Strings("core_unknown_entity_id", identifier.id));
      } else if (identifier.id != -1) {
        return find_entity<Type>(entities, identifier.id);
      } else {
        return find_entity<Type>(entities, identifier.name);
      }
    }
  };
}

template<typename Type = macroengine::entity::Entity>
Type				&findEntity(macroengine::configuration::t_built_entities &entities, std::string const &name) {
  return macroengine::FindEntity::find_entity<Type>(entities, name);
}

template<typename Type = macroengine::entity::Entity>
Type				&findEntity(macroengine::configuration::t_built_entities &entities, macroengine::t_entity_id const &id) {
  return macroengine::FindEntity::find_entity<Type>(entities, id);
}

template<typename Type = macroengine::entity::Entity>
Type				&findEntity(macroengine::configuration::t_built_entities &entities, macroengine::t_identifier const &identifier) {
  return macroengine::FindEntity::find_entity<Type>(entities, identifier);
}

#endif /* !MACRO_ENGINE_FIND_ENTITY_HPP_ */
