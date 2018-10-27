//
// TextWrapper.cpp for macroengine in /home/sylvain/Documents/projets/perso/macroengine
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Wed Apr 25 15:03:58 2018 Sylvain Chaugny
// Last update Wed Apr 25 15:05:01 2018 Sylvain Chaugny
//

# include			"macroengine-core/utl/strings.hpp"
# include			"macroengine-core/utl/exceptions.hpp"
# include			"macroengine-core/utl/configuration.hpp"
#include			"TextWrapper.hpp"

macroengine::graphics::Text	&macroengine::graphics::TextWrapper::addFromIni(std::string const &name, std::string const &path) {
  t_identifier 			identifier;

  identifier.id = EntityIDGenerator.newID();
  identifier.name = name;
  _texts[identifier].loadFromIni(path);
  _texts[identifier].setIdentifier(identifier);
  return _texts[identifier];
}

macroengine::graphics::Text	&macroengine::graphics::TextWrapper::get(std::string const &name) {
  for (auto &&text: _texts) {
    if (text.first.name == name) {
      return text.second;
    }
  }
  throw exception::UnknownTextNameException(Strings("core_unknown_text_name", name));
}

macroengine::graphics::Text	&macroengine::graphics::TextWrapper::get(macroengine::t_entity_id const &id) {
  for (auto &&text: _texts) {
    if (text.first.id == id) {
      return text.second;
    }
  }
  throw exception::UnknownTextIDException(Strings("core_unknown_text_id", id));
}

macroengine::graphics::Text	&macroengine::graphics::TextWrapper::get(const macroengine::t_identifier &identifier) {
  if (identifier.filled()) {
    if (_texts.find(identifier) != _texts.end()) {
      return _texts[identifier];
    }
    throw exception::UnknownTextIDException(Strings("core_unknown_text_id", identifier.id));
  } else if (identifier.id != -1) {
    return get(identifier.id);
  } else {
    return get(identifier.name);
  }
}
