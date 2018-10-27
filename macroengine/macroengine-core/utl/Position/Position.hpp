/*
** Position.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/utl/Position/Position.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 25 01:17:41 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_POSITION_HPP_
# define MACRO_ENGINE_POSITION_HPP_

# include				<cstddef>
# include				<SFML/System.hpp>


namespace 				macroengine {
  namespace 				utl {
    /**
     * \class Position
     * \brief Provides a position utility class for every classs needing this kind of data (views, game logic...).
     */
    class				Position {
    public:
      float				x;
      float				y;

    public:
      Position(float _x = 0, float _y = 0);
      Position(Position const &pos);
      Position(sf::Vector2i const &pos);

      /**
       * Sets itself to another Position.
       * @param pos the other Position
       * @return a reference on itself
       */
      Position			&operator=(Position const &pos);

      /**
       * Sets itself to a sf::Vector2i (for SFML compatibility).
       * @param pos the sf::Vector2i
       * @return
       */
      Position			&operator=(sf::Vector2i const &pos);

      /**
       * Checks whether itself is equal to a sf::Vector2i.
       * @param pos the sf::Vector2i
       * @return true if both variables are equal false otherwise
       */
      bool				operator==(sf::Vector2i const &pos) const;

      /**
       * Checks whether itself is equal to another Position.
       * @param pos the other Position
       * @return true if both variables are equal false otherwise
       */
      bool				operator==(Position const &pos) const;

      /**
       * Checks whether itself is different from another Position.
       * @param pos the other Position
       * @return true if both variables are different, false otherwise
       */
      bool				operator!=(Position const &pos) const;

      /**
       * Converts itself to a sf::Vector2i (for SFML compatibility).
       * @return a newly created sf::Vector2i
       */
      sf::Vector2f			toSfVector2f();

      /**
       * Checks whether the position is greater than the other or not.
       */
       bool				operator>(Position const &pos) const;

      /**
       * Checks whether the position is greater than the other or not.
       */
      bool				operator>=(Position const &pos) const;

      /**
       * Checks whether the position is smaller than the other or not.
       */
      bool				operator<(Position const &pos) const;

      /**
       * Checks whether the position is smaller than the other or not.
       */
      bool				operator<=(Position const &pos) const;
    };
  }
}

namespace				std
{
  template <>
  struct				hash<macroengine::utl::Position>
  {
    std::size_t				operator()(const macroengine::utl::Position& v) const {
      using				std::size_t;
      using				std::hash;
      using				std::string;

      return ((hash<float>()(v.x) ^ (hash<float>()(v.y) << 1)) >> 1);
    }
  };
}


#endif /* !MACRO_ENGINE_POSITION_HPP_ */
