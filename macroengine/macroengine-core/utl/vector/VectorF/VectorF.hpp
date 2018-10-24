/*
** VectorF.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/utl/vector/VectorF/VectorF.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sat Mar 03 13:37:32 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_VECTORF_HPP_
# define MACRO_ENGINE_VECTORF_HPP_

namespace 				macroengine {
  namespace 				utl {
    /**
     * \struct VectorF
     * \brief [UNUSED] Implementation of the sf::Vector3f class.
     */
    struct				VectorF {
      VectorF(float x = 0, float y = 0, float z = 0);
      VectorF(VectorF const &obj);

      VectorF				&operator=(VectorF const &obj);

      float				x;
      float				y;
      float				z;
    };
  }
}

#endif /* !MACRO_ENGINE_VECTORF_HPP_ */
