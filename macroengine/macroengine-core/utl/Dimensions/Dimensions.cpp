/*
** Dimensions.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/utl/Dimensions/Dimensions.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon Mar 19 10:59:57 2018 Sylvain CHAUGNY
*/

#include			"Dimensions.hpp"

macroengine::utl::Dimensions::Dimensions(size_t width, size_t height) :
  width(width),
  height(height) {
}

void				macroengine::utl::Dimensions::operator+=(macroengine::utl::Dimensions const &dimensions) {
  height += dimensions.height;
  width += dimensions.width;
}

macroengine::utl::Dimensions	&macroengine::utl::Dimensions::operator=(const macroengine::utl::Dimensions &dim) {
  width = dim.width;
  height = dim.height;
  return *this;
}

void				macroengine::utl::Dimensions::operator*=(const macroengine::utl::Dimensions &dim) {
  width *= dim.width;
  height *= dim.height;
}
