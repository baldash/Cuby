/*
** EntityIDGenerator.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/configuration/EntityIDGenerator/EntityIDGenerator.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Mar 14 17:10:15 2018 Sylvain CHAUGNY
*/

# include				"macroengine-core/utl/macros/macros_definitions.hpp"
#include				"EntityIDGenerator.hpp"

macroengine::configuration::EntityIDGenerator::EntityIDGenerator() :
  _id(MACROENGINE_VAR_DEFAULT_ENTITY_ID_START - 1) {
}

macroengine::t_entity_id	macroengine::configuration::EntityIDGenerator::newID() {
  _id++;
  return _id;
}
