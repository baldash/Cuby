/*
** Object.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/Object/Object.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Feb 14 20:16:54 2018 Sylvain CHAUGNY
*/

# include 			"macroengine-core/utl/strings.hpp"
# include			"macroengine-core/log/log.hpp"
# include			"macroengine-core/Object/Object.hpp"

macroengine::Object::Object() :
  _class_name(Strings("core_unknown_class_name")),
  _identifier({-1, ""}) {
}

macroengine::Object::Object(std::string const &name) :
  _class_name(name) {
}

void				macroengine::Object::setClassName(const std::string &str) {
  _class_name = str;
}

std::string const		&macroengine::Object::getClassName() {
  return _class_name;
}

void				macroengine::Object::error(const std::string &str, size_t indentation) {
  Error::display("[ " + _class_name + " ] " + std::string(indentation, ' ') + str);
}

void				macroengine::Object::warning(const std::string &str, size_t indentation) {
  Warning::display("[ " + _class_name + " ] " + std::string(indentation, ' ') + str);
}

void				macroengine::Object::log(const std::string &str, size_t indentation) {
  Log::display("[ " + _class_name + " ] " + std::string(indentation, ' ') + str);
}

const macroengine::t_entity_id	&macroengine::Object::getID() {
  return _identifier.id;
}

void				macroengine::Object::setID(const macroengine::t_entity_id &id) {
  _identifier.id = id;
}

const macroengine::t_identifier	&macroengine::Object::getIdentifier() const {
  return _identifier;
}

void				macroengine::Object::setName(std::string const &name) {
  _identifier.name = name;
}

std::string const		&macroengine::Object::getName() {
  return _identifier.name;
}

void				macroengine::Object::setIdentifier(const macroengine::t_identifier &identifier) {
  _identifier.id = identifier.id;
  _identifier.name = identifier.name;
  if (_class_name == "") {
    _class_name = _identifier.name;
  }
}
