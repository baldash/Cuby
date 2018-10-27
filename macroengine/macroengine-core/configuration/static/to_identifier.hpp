/*
** to_identifier.hpp for macroengine in /home/sylvain/Documents/projets/perso/macroengine/macroengine/configuration/static/to_identifier.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon Apr 30 09:31:17 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_TO_IDENTIFIER_HPP_
# define MACRO_ENGINE_TO_IDENTIFIER_HPP_

# include				"macroengine-core/utl/types.hpp"

namespace				macroengine {
  /**
   * \class ToIdentifier
   * \brief This class contains a set of to_identifier functions, each of them returning a newly created macroengine::t_identifier from given parameters.
   * These functions should be accessed by the toIdentifier macro.
   */
  class					ToIdentifier {
  public:
    static macroengine::t_identifier	to_identifier(std::string const &name) {
      macroengine::t_identifier identifier;

      identifier.id = -1;
      identifier.name = name;
      return identifier;
    }

    static macroengine::t_identifier	to_identifier(macroengine::t_entity_id const &id) {
      macroengine::t_identifier identifier;

      identifier.id = id;
      identifier.name = "";
      return identifier;
    }

    static macroengine::t_identifier	to_identifier(macroengine::t_entity_id const &id, std::string const &name) {
      macroengine::t_identifier identifier;

      identifier.id = id;
      identifier.name = name;
      return identifier;
    }

    static macroengine::t_identifier	to_identifier(std::string const &name, macroengine::t_entity_id const &id) {
      macroengine::t_identifier identifier;

      identifier.id = id;
      identifier.name = name;
      return identifier;
    }
  };
}

#endif /* !MACRO_ENGINE_TO_IDENTIFIER_HPP_ */
