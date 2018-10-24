/*
** VectorF.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/utl/vector/VectorF/VectorF.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sat Mar 03 13:38:56 2018 Sylvain CHAUGNY
*/

#include			"VectorF.hpp"

macroengine::utl::VectorF::VectorF(float _x, float _y, float _z) :
  x(_x), y(_y), z(_z) {

}

macroengine::utl::VectorF::VectorF(const macroengine::utl::VectorF &obj) :
  x(obj.x), y(obj.y), z(obj.z) {
}

macroengine::utl::VectorF	&macroengine::utl::VectorF::operator=(const macroengine::utl::VectorF &obj) {
  x = obj.x;
  y = obj.y;
  z = obj.z;
  return *this;
}
