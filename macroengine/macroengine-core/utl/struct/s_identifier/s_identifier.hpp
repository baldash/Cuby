/*
** s_identifier.hpp for macroengine in /home/sylvain/Documents/projets/perso/macroengine/macroengine/utl/struct/s_identifier.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed May 02 13:03:55 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_S_IDENTIFIER_HPP_
# define MACRO_ENGINE_S_IDENTIFIER_HPP_

# include				<string>

namespace				macroengine {
  namespace 				utl {
    /**
     * \struct s_identifier
     * \brief The main identifier for every created entity in the Macro Engine system.
     * This class provides a unique id and a name, defining an entity (the id is of the same type as a t_entity_id).
     */
    struct				s_identifier {
      long				id;
      std::string			name;

      s_identifier();

      /**
       * This constructor directly gets the identifier members as parameter.
       * @param id the id
       * @param name the name
       */
      s_identifier(long id, std::string const &name);

      /**
       * Copy constructor.
       * @param op another s_identifier
       */
      s_identifier(s_identifier const &op);

      /**
       * Sets its values from the other s_identifier.
       * @param op the other s_identifier
       * @return a reference on itself
       */
      s_identifier			&operator=(s_identifier const &op);

      /**
       * Checks whether all its fields are equal to the other s_identifier fields.
       * @param op the other s_identifier
       * @return true if the 2 match, false otherwise
       */
      bool				operator==(s_identifier const &op) const;

      /**
       * Checks whether at least one of its fields is not equal to the other s_identifier fields.
       * @param op the other s_identifier
       * @return true if the 2 don't match, false otherwise
       */
      bool				operator!=(s_identifier const &op) const;

      /**
       * Checks whether its id is shorter than the other s_identifier id.
       * @param op the other s_identifier
       * @return true if its is shorter, false otherwise
       */
      bool				operator<(s_identifier const &op) const;

      /**
       * Checks whether its id is bigger than the other s_identifier id.
       * @param op the other s_identifier
       * @return true if its is bigger, false otherwise
       */
      bool				operator>(s_identifier const &op) const;

      /**
       * Gets a string formatted as "[id = 'its id', name=<'its name'>]" for debug purposes.
       * @return the formatted string
       */
      std::string			getDebugString() const;

      /**
       * Checks whether its 2 fields are not empty.
       * @return true if both are not empty, false otherwise
       */
      bool				filled() const;

      /**
       * Checks whether its 2 fields are empty.
       * @return true if both are empty, false otherwise
       */
      bool				empty() const;
    };
  }
}

#endif /* !MACRO_ENGINE_S_IDENTIFIER_HPP_ */
