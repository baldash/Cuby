/*
** Animation.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/Animation/Animation.cpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Mar 01 16:50:01 2018 Sylvain CHAUGNY
*/

# include					"macroengine-core/utl/strings.hpp"
# include					"macroengine-core/utl/configuration.hpp"
#include					"Animation.hpp"

macroengine::graphics::Animation::Animation() :
  _paused(false),
  _started(false) {
}

macroengine::graphics::Animation		&macroengine::graphics::Animation::loadFromIni(std::string const &ini_file) {
  parser::ini::IniParser			ini;

  _data_file.close();
  log(Strings("core_building_animation", ini_file));
  _data_file.setFileName(ini_file);
  _data_file.open();
  if (!_data_file.good() || _data_file.read()) {
    error(Strings("core_fail_opening_file", ini_file));
    return *this;
  }
  if (ini.parseFromFile(_data_file)) {
    return *this;
  }
  if (!ini.scopeExists("FILE") || !ini.scopeExists("DATA") || !ini.scopeExists("PROPERTIES")) {
    error(Strings("core_missing_informations_in_ini", _data_file.getFileName()));
    return *this;
  }
  start();
  loadData(ini);
  return *this;
}

int						macroengine::graphics::Animation::loadData(macroengine::parser::ini::IniParser &parser) {
  _animation_data.sprites.clear();
  _animation_data.path = (parser["FILE"].keyExists("path")) ? parser["FILE"]["path"] : "";
  _animation_data.frames = (parser["DATA"].keyExists("frames")) ? std::stoul(parser["DATA"]["frames"]) : 0;
  _animation_data.frame_dimensions.width = (parser["DATA"].keyExists("frame_width")) ? std::stoul(parser["DATA"]["frame_width"]) : 0;
  _animation_data.frame_dimensions.height = (parser["DATA"].keyExists("frame_height")) ? std::stoul(parser["DATA"]["frame_height"]) : 0;
  _animation_data.duration = (parser["PROPERTIES"].keyExists("duration")) ? getDuration(parser["PROPERTIES"]["duration"]) : getDuration("0s0ms0mms");
  _animation_data.looped = (parser["PROPERTIES"].keyExists("looped_by_default")) ? parser["PROPERTIES"]["looped_by_default"] == "true" : false;
  _animation_data.frame_duration = clock::Time(0, 0, _animation_data.duration.asMicroseconds() / _animation_data.frames);
  _animation_data.delay_id = CoreClock.newDelay(_animation_data.frame_duration);
  _animation_data.index = 0;
  _animation_data.position = macroengine::utl::Position();
  return loadSpriteSheet();
}

macroengine::clock::Time			macroengine::graphics::Animation::getDuration(std::string const &format) {
  std::string					tmp;
  float						s;
  int						ms;
  long						mms;

  tmp = format.substr(0, format.find("s"));
  s = static_cast<float>(strtod(tmp.c_str(), nullptr));
  tmp = format.substr(format.find("s") + 1, format.find("ms"));
  ms = static_cast<int>(strtol(tmp.c_str(), nullptr, 10));
  tmp = format.substr(format.find("ms") + 2, format.find("mms"));
  mms = strtol(tmp.c_str(), nullptr, 10);
  return macroengine::clock::Time(s >= 0 ? s : 0, ms >= 0 ? ms : 0, mms >= 0 ? mms : 0);
}

int						macroengine::graphics::Animation::loadSpriteSheet() {
  if (!_animation_data.texture.loadFromFile(_animation_data.path)) {
    error(Strings("core_texture_not_found", _animation_data.path));
    return 1;
  }
  for (std::size_t i = 0; i < _animation_data.frames; i++) {
    sf::Sprite sprite;

    sprite.setTexture(_animation_data.texture);
    sprite.setTextureRect(sf::IntRect(i * _animation_data.frame_dimensions.width, 0,
				      _animation_data.frame_dimensions.width, _animation_data.frame_dimensions.height));
    _animation_data.sprites.emplace_back(sprite);
  }
  log(Strings("core_success"));
  return 0;
}

macroengine::graphics::utl::AnimationData	&macroengine::graphics::Animation::getData() {
  return _animation_data;
}

macroengine::graphics::Animation		&macroengine::graphics::Animation::start() {
  _started = true;
  _animation_data.index = 0;
  return *this;
}

macroengine::graphics::Animation		&macroengine::graphics::Animation::stop() {
  _started = false;
  return *this;
}

macroengine::graphics::Animation		&macroengine::graphics::Animation::pause() {
  _paused = true;
  return *this;
}

macroengine::graphics::Animation		&macroengine::graphics::Animation::resume() {
  _paused = false;
  return *this;
}

bool 						macroengine::graphics::Animation::isStarted() {
  return _started;
}

bool 						macroengine::graphics::Animation::isPaused() {
  return _paused;
}

sf::Sprite const 				&macroengine::graphics::Animation::getCurrentFrame() {
  return _animation_data.sprites[_animation_data.index];
}

macroengine::graphics::Animation		&macroengine::graphics::Animation::update() {
  _animation_data.index++;
  if (_animation_data.looped) {
    _animation_data.index = (_animation_data.index == _animation_data.frames) ? 0 : _animation_data.index;
  } else {
    _animation_data.index -= (_animation_data.index == _animation_data.frames) ? 1 : 0;
  }
  return *this;
}

macroengine::graphics::Animation		&macroengine::graphics::Animation::setLoop(bool loop) {
  _animation_data.looped = loop;
  return *this;
}

int						macroengine::graphics::Animation::getDelayID() {
  return _animation_data.delay_id;
}

macroengine::utl::Position			&macroengine::graphics::Animation::getPosition() {
  return _animation_data.position;
}

macroengine::graphics::Animation		&macroengine::graphics::Animation::setPosition(const macroengine::utl::Position &pos) {
  _animation_data.position = pos;
  for (auto &&sprite: _animation_data.sprites) {
    sprite.setPosition(pos.x, pos.y);
  }
  return *this;
}

void						macroengine::graphics::Animation::dump() {
}

macroengine::graphics::Animation		&macroengine::graphics::Animation::move(int x, int y) {
  for (auto &&sprite: _animation_data.sprites) {
    sprite.setPosition(sprite.getPosition().x + x, sprite.getPosition().y + y);
  }
  return *this;
}

macroengine::graphics::Animation		&macroengine::graphics::Animation::move(const macroengine::utl::Position &pos) {
  for (auto &&sprite: _animation_data.sprites) {
    sprite.setPosition(sprite.getPosition().x + pos.x, sprite.getPosition().y + pos.y);
  }
  return *this;
}

macroengine::graphics::Animation		&macroengine::graphics::Animation::updateWithClock() {
  if (CoreClock.isDelayOver(_animation_data.delay_id)) {
    update();
  }
  return *this;
}
