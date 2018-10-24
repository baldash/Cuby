/*
** Animable.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/component/Animable/Animable.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Feb 15 00:17:45 2018 Sylvain CHAUGNY
*/

# include						"macroengine-core/utl/macros/macros_attributes.hpp"
# include						"macroengine-core/utl/configuration.hpp"
#include						"Scriptable.hpp"

macroengine::entity::component::Scriptable::Scriptable() {
}

macroengine::entity::component::ScriptableCallableParams	&macroengine::entity::component::Scriptable::addTimedCallable(std::string const &name, macroengine::controller::t_callable callable, const macroengine::clock::Time &time) {
  ScriptableCallableParams		params;

  params.callable = callable;
  params.identifier.name = name;
  params.identifier.id = EntityIDGenerator.newID();
  params.delay_id = CoreClock.newDelay(time);
  params.data.ticks = 0;
  _callables[params.identifier] = params;
  return _callables[params.identifier];
}

macroengine::entity::component::ScriptableCallableParams	&macroengine::entity::component::Scriptable::addTimedCallable(std::string const &name, controller::t_callable callable, macroengine::clock::t_delay_id id) {
  ScriptableCallableParams			params;

  params.callable = callable;
  params.identifier.name = name;
  params.identifier.id = EntityIDGenerator.newID();
  params.delay_id = id;
  params.data.ticks = 0;
  _callables[params.identifier] = params;
  return _callables[params.identifier];
}

void							macroengine::entity::component::Scriptable::removeCallable(macroengine::t_entity_id const &id) {
  for (auto &&callable: _callables) {
    if (callable.first.id == id) {
      _callables.erase(callable.first);
      return ;
    }
  }
}

void							macroengine::entity::component::Scriptable::removeCallable(std::string const &name) {
  for (auto &&callable: _callables) {
    if (callable.first.name == name) {
      _callables.erase(callable.first);
      return ;
    }
  }
}

macroengine::entity::component::t_callables		&macroengine::entity::component::Scriptable::getCallables() {
  return _callables;
}

void							macroengine::entity::component::Scriptable::removeCallable(const macroengine::t_identifier &identifier) {
  if (identifier.id != -1) {
    removeCallable(identifier.id);
  } else {
    removeCallable(identifier.name);
  }
}
