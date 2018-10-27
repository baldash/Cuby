/*
** GeneralController.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/controller/GeneralController/GeneralController.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 18 20:40:37 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_GENERALCONTROLLER_HPP
#define MACRO_ENGINE_GENERALCONTROLLER_HPP

# include					"macroengine-core/controller/event/EventController/EventController.hpp"
# include					"macroengine-core/controller/component/ScriptableController/ScriptableController.hpp"
# include					"macroengine-core/controller/Renderer/Renderer.hpp"
# include					"macroengine-core/controller/component/CollidableController/CollidableController.hpp"
# include					"macroengine-core/controller/component/ControllableController/ControllableController.hpp"
# include					"macroengine-core/controller/component/MovableController/MovableController.hpp"
# include					"macroengine-core/controller/component/DrawableController/DrawableController.hpp"
# include					"macroengine-core/configuration/EntityRegister/EntityRegister.hpp"
# include					"macroengine-core/controller/AController/AController.hpp"

namespace 					macroengine {
  namespace 					controller {
    /**
     * \class GeneralController
     * \brief The main controller class, which updates every entity component created by the core of the user.
     * It has several controller instances to update every type of entity component (see the examples for more infos).
     * This class should not be used by the user.
     */
    class					GeneralController : public Object {
    private:
      component::CollidableController		_collidable_controller;
      component::ControllableController		_controllable_controller;
      component::DrawableController		_drawable_controller;
      component::MovableController		_movable_controller;
      component::ScriptableController		_scriptable_controller;

      Renderer					_renderer;
      EventController				_event_controller;

      configuration::t_built_entities		_entities;
      t_sorted_entities 			_sorted;

      configuration::game::GameConfiguration	_game_configuration;

    public:
      GeneralController();
      virtual ~GeneralController() = default;

      virtual void				dump() override;

      /**
       * Initialization method called by the core.
       * @return 0 if OK, 1 otherwise
       */
      int					configure();

      /**
       * Init method called by the core.
       * @param game The game configuration class already configured by the Configuration class
       * @return 0 if OK, 1 otherwise
       */
      virtual int				init(configuration::game::GameConfiguration &game, configuration::t_built_entities &entities);

      /**
       * Update method called by the Core.
       * This will update every entity by calling every AController inherited class update() method.
       * @return 0 if OK, 1 otherwise
       */
      int					update();

      /**
       * Checks whether the game is running or not.
       * @return true if the game is running, false otherwise
       */
      bool					isRunning();

    private:
      void					retrieveEntities();
      void					sortBuiltEntities(configuration::t_built_entities &entities);
    };
  }
}

#endif //MACRO_ENGINE_GENERALCONTROLLER_HPP
