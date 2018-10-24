/*
** EntityIDGenerator.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/configuration/EntityIDGenerator/EntityIDGenerator.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Mar 14 17:08:56 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_ENTITYIDGENERATOR_HPP
#define MACRO_ENGINE_ENTITYIDGENERATOR_HPP

# include				"macroengine-core/utl/types.hpp"

namespace 				macroengine {
  namespace 				configuration {
    /**
     * \class EntityIDGenerator
     * \brief Provides an entity ID generator accessible to practically every Macro Engine class.
     * This class should not be called by the user (see examples for which macro to use).
     */
    class				EntityIDGenerator {
    private:
      t_entity_id 			_id;

    public:
      EntityIDGenerator();
      virtual ~EntityIDGenerator() = default;

      /**
       * returns a new t_entity_id and increments its internal id counter, so that unique IDs only will be generated.
       * @return the newly created t_entity_id
       */
      t_entity_id 			newID();
    };
  }
}

#endif //MACRO_ENGINE_ENTITYIDGENERATOR_HPP
