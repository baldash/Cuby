/*
** Renderer.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/controller/Renderer/Renderer.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Feb 23 14:38:09 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_RENDERER_HPP
#define MACRO_ENGINE_RENDERER_HPP

# include				<SFML/Graphics.hpp>
# include				"macroengine-core/configuration/game/GameWindowConfiguration/GameWindowConfiguration.hpp"
# include				"macroengine-core/utl/macros/macros_misc.hpp"
# include				"macroengine-core/entity/property/enum/e_property.hpp"
# include				"macroengine-core/Object/Object.hpp"
# include				"macroengine-core/entity/Entity/Entity.hpp"

namespace 				macroengine {
  namespace 				controller {

    /**
     * \class Renderer
     * \brief This class displays all the Macro Engine Drawable elements.
     * This wraps the sf::RenderWindow class and is used as a bridge to display all the Drawable entities from every View inside the window.
     */
    class				Renderer : public Object {
    private:
      sf::RenderWindow			_render_window;

    public:
      Renderer();
      virtual ~Renderer() = default;

      virtual void			dump() override;

      /**
       * Initialization method called by the GeneralController.
       * @param config the window configuration
       * @return 0 if OK, 1 otherwise
       */
      int				configure(configuration::game::GameWindowConfiguration &config);

      /**
       * update method called by the GeneralController. This will update every DRAWABLE entity.
       * @param entities the list of DRAWABLE entities
       * @param total every known entity
       * @return 0 if OK, 1 otherwise
       */
      int				update(configuration::t_built_entities &entities, configuration::t_built_entities &total);

      /**
       * Gets the SFML window.
       * @return the window
       */
      sf::RenderWindow			&getWindow();

    private:
      int				updateSprite(configuration::t_built_entity &, configuration::t_built_entities &, graphics::View &view);
      int				updateAnimation(configuration::t_built_entity &, configuration::t_built_entities &, graphics::View &view);
      int				updateText(configuration::t_built_entity &, configuration::t_built_entities &, graphics::View &view);
      int				updateShape(configuration::t_built_entity &, configuration::t_built_entities &, graphics::View &view);
      int				updateView(configuration::t_built_entity &, configuration::t_built_entities &, graphics::View &view);
    };
  }
}

#endif //MACRO_ENGINE_RENDERER_HPP
