/*
** ShapeWrapper.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/drawable/shape/ShapeWrapper/ShapeWrapper.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon Mar 19 11:27:40 2018 Sylvain CHAUGNY
*/

#include					"ShapeWrapper.hpp"
# include					"macroengine-core/utl/configuration.hpp"

macroengine::graphics::ShapeWrapper::ShapeWrapper() {
}

void						macroengine::graphics::ShapeWrapper::dump() {
}

macroengine::graphics::RectangleShape		&macroengine::graphics::ShapeWrapper::addRectangleShape(std::string const &name) {
  t_identifier 					identifier;

  identifier.id = EntityIDGenerator.newID();
  identifier.name = name;
  _rectangle_shapes[identifier].setIdentifier(identifier);
  return _rectangle_shapes[identifier];
}

void						macroengine::graphics::ShapeWrapper::removeRectangleShape(macroengine::t_entity_id const &id) {
  for (t_rectangle_shapes::iterator i = _rectangle_shapes.begin(); i != _rectangle_shapes.end(); i++) {
    if (i->first.id == id) {
      _rectangle_shapes.erase(i);
      return ;
    }
  }
}

void						macroengine::graphics::ShapeWrapper::removeRectangleShape(std::string const &name) {
  for (t_rectangle_shapes::iterator i = _rectangle_shapes.begin(); i != _rectangle_shapes.end(); i++) {
    if (i->first.name == name) {
      _rectangle_shapes.erase(i);
      return ;
    }
  }
}

macroengine::graphics::t_rectangle_shapes	&macroengine::graphics::ShapeWrapper::getRectangleShapes() {
  return _rectangle_shapes;
}

void						macroengine::graphics::ShapeWrapper::removeRectangleShape(const macroengine::t_identifier &identifier) {
  if (identifier.id != -1) {
    removeRectangleShape(identifier.id);
  } else {
    removeRectangleShape(identifier.name);
  }
}
