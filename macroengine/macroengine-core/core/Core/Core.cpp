/*
** Core.cpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/core/Core/Core.cpp
**
** Made by Sylvain CHAUGNY
** Warningin   <sylvain.chaugny@epitech.eu>
**
** Started on  Tue Feb 13 23:19:34 2018 Sylvain CHAUGNY
*/

# include					"macroengine-core/utl/strings.hpp"
# include					"macroengine-core/utl/configuration.hpp"
# include					"macroengine-core/log/log.hpp"
#include					"Core.hpp"

macroengine::core::Core::Core() :
  Object("Core"),
  _clock(),
  _running(false),
  _debug_mode(MACROENGINE_VAR_DEBUG_MODE_NONE) {
}

macroengine::configuration::Configuration	&macroengine::core::Core::getConfiguration() {
  return _configuration;
}

int						macroengine::core::Core::run() {
  if (configure()) {
    return 1;
  }
 _running = isRunnable();
  if (_running) {
    Warning::display(Strings("core_running_engine"));
    _clock.setCoreFrequency(MACROENGINE_VAR_DEFAULT_CORE_FREQUENCY);
  }
 while (_general_controller.isRunning() && isRunning()) {
   _general_controller.update();
   _clock.update();
 }
  return 0;
}

void						macroengine::core::Core::dump() {
}

int						macroengine::core::Core::configure() {
  int						ret;

  ret = 0;
  ret += getConfiguration().configure();
  ret += getGeneralController().init(getConfiguration().getGameConfiguration(), getConfiguration().getEntityRegister().getAll());
  return ret != 0;
}

macroengine::controller::GeneralController	&macroengine::core::Core::getGeneralController() {
  return _general_controller;
}

macroengine::clock::Clock			&macroengine::core::Core::getClock() {
  return _clock;
}

int						macroengine::core::Core::stop() {
  _running = false;
  Warning::display(Strings("core_stopping_engine"));
  return 0;
}

bool						macroengine::core::Core::isRunning() {
  return _running;
}

bool						macroengine::core::Core::isRunnable() {
  switch (_debug_mode) {
    case MACROENGINE_VAR_DEBUG_MODE_NONE:
      return true;
    case MACROENGINE_VAR_DEBUG_MODE_CONFIGURATION_ONLY:
      return false;
    default:
      return false;
  }
}

void						macroengine::core::Core::setCoreDebugMode(int val) {
  _debug_mode = val;
}
