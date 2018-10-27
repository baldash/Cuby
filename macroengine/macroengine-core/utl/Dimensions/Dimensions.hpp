/*
** Dimensions.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/utl/Dimensions/Dimensions.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Mar 01 17:30:39 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_DIMENSIONS_HPP_
# define MACRO_ENGINE_DIMENSIONS_HPP_

# include				<cstddef>

namespace 				macroengine {
  namespace 				utl {
    /**
     * \class Dimensions
     * \brief Container used to define dimensions for every class needing it (shapes, views, windows...).
     */
    struct				Dimensions {
      std::size_t			width = 0;
      std::size_t			height = 0;

      Dimensions() = default;
      Dimensions(size_t width, size_t height);

      /**
       * Adds two Dimensions classes.
       * @param dim the other Dimensions
       */
      void				operator+=(Dimensions const &dim);

      /**
       * Multiplies two Dimensions classes (width with width, height with height).
       * @param dim the other Dimensions
       */

      void				operator*=(Dimensions const &dim);

      /**
       * Sets a Dimensions from the other.
       * @param dim the other Dimensions
       * @return a reference on itself
       */
      Dimensions			&operator=(Dimensions const &dim);
    };
  }
}

#endif /* !MACRO_ENGINE_DIMENSIONS_HPP_ */
