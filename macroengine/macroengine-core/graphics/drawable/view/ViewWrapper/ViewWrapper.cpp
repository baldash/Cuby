/*
** ViewWrapper.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/drawable/view/ViewWrapper/ViewWrapper.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Apr 13 18:52:13 2018 Sylvain CHAUGNY
*/

# include					"macroengine-core/utl/strings.hpp"
# include					"macroengine-core/utl/exceptions.hpp"
# include					"macroengine-core/utl/configuration.hpp"
#include					"ViewWrapper.hpp"

macroengine::graphics::ViewWrapper::ViewWrapper() :
  Object("ViewWrapper") {
}

macroengine::graphics::View			&macroengine::graphics::ViewWrapper::add(std::string const &name, macroengine::utl::Dimensions const &dim) {
  return add(name, dim.width, dim.height);
}

macroengine::graphics::View			&macroengine::graphics::ViewWrapper::add(std::string const &name, size_t width, size_t height) {
  t_identifier 					identifier;

  log(Strings("core_creating_view", name, width, height));
  identifier.id = EntityIDGenerator.newID();
  identifier.name = name;
  _views[identifier].setIdentifier(identifier);
  _views[identifier].setDimensions(macroengine::utl::Dimensions(width, height));
  _views[identifier].init();
  return _views[identifier];
}

void						macroengine::graphics::ViewWrapper::dump() {
}

macroengine::graphics::t_views			&macroengine::graphics::ViewWrapper::getAll() {
  return _views;
}

macroengine::graphics::View			&macroengine::graphics::ViewWrapper::get(const macroengine::t_identifier &identifier) {
  if (identifier.filled()) {
    if (_views.find(identifier) != _views.end()) {
      return _views[identifier];
    }
    throw exception::UnknownViewIDException(Strings("core_unknown_view_id", identifier.id));
  } else if (identifier.id != -1) {
    return get(identifier.id);
  } else {
    return get(identifier.name);
  }
}

macroengine::graphics::View			&macroengine::graphics::ViewWrapper::get(const macroengine::t_entity_id &id) {
  for (auto &&view: _views) {
    if (view.first.id == id) {
      return view.second;
    }
  }
  throw exception::UnknownViewIDException(Strings("core_unknown_view_id", id));
}

macroengine::graphics::View			&macroengine::graphics::ViewWrapper::get(std::string const &name)
{
  for (auto &&view: _views) {
    if (view.first.name == name) {
      return view.second;
    }
  }
  throw exception::UnknownViewNameException(Strings("core_unknown_view_name", name));
}

void						macroengine::graphics::ViewWrapper::remove(std::string const &name) {
  for (t_views::iterator i = _views.begin(); i != _views.end(); i++) {
    if (i->first.name == name) {
      _views.erase(i);
      return ;
    }
  }
  throw exception::UnknownViewNameException(Strings("core_unknown_view_name", name));
}

void						macroengine::graphics::ViewWrapper::remove(const macroengine::t_entity_id &id) {
  for (t_views::iterator i = _views.begin(); i != _views.end(); i++) {
    if (i->first.id == id) {
      _views.erase(i);
      return ;
    }
  }
  throw exception::UnknownViewIDException(Strings("core_unknown_view_id", id));
}

void						macroengine::graphics::ViewWrapper::remove(const macroengine::t_identifier &identifier) {
  if (identifier.id != -1) {
    remove(identifier.id);
  } else {
    remove(identifier.name);
  }
}
