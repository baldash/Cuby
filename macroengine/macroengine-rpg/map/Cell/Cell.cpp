/*
** Cell.cpp for Macro_Engine in /home/sylvain/Documents/projects/perso/C++/macroengine/macroengine-rpg/map/Cell/Cell.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sat Jun 02 00:28:44 2018 Sylvain CHAUGNY
*/

#include				"Cell.hpp"

macroengine::rpg::map::Cell::Cell(macroengine::rpg::map::CellData const &data) :
  _data(data) {
}

void					macroengine::rpg::map::Cell::dump() {
}

const macroengine::rpg::map::CellData	&macroengine::rpg::map::Cell::getCellData() const {
  return _data;
}

void					macroengine::rpg::map::Cell::setCellFlag(const char &f) {
  _data.flag = f;
}

void					macroengine::rpg::map::Cell::setCellData(const macroengine::rpg::map::CellData &data,
										     const macroengine::utl::Position &position,
										     const macroengine::graphics::Sprite &sprite) {
  _data.crossable = data.crossable;
  _data.crossable_by_player = data.crossable_by_player;
  _data.dimensions = data.dimensions;
  _data.name = data.name;
  _data.texture_file = data.texture_file;
  _data.position = position;
  _data.sprite = sprite;
}

void					macroengine::rpg::map::Cell::init(std::string const &name) {
  setName(name);
  setID(EntityIDGenerator.newID());
}