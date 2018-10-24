/*
** DrawableController.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/controller/DrawableController/DrawableController.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 18 21:16:21 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_DRAWABLECONTROLLER_HPP
#define MACRO_ENGINE_DRAWABLECONTROLLER_HPP

# include				"macroengine-core/controller/AController/AController.hpp"

namespace				macroengine {
  namespace 				controller {
    namespace 				component {
      /**
       * \class DrawableController
       * \brief The controller specialized for the propery::DRAWABLE components.
       * This class should not be used by the user.
       */
      class				DrawableController : public AController<property::DRAWABLE> {
      private:
	t_animations			_animations;

      public:
	DrawableController() = default;
	virtual ~DrawableController() = default;

	virtual void			dump() override;

	/**
	 * initialization method, called by the GeneralController
	 * @return 0 if OK, 1 otherwise
	 */
	int				configure();

	/**
	 * \sa macroengine::controller::AController
	 */
	virtual int			stop() override;


	/**
	 * \sa macroengine::controller::AController
	 */
	virtual int			update(configuration::t_built_entities &, configuration::t_built_entities &) override;
      };
    }
  }
}

#endif //MACRO_ENGINE_DRAWABLECONTROLLER_HPP
