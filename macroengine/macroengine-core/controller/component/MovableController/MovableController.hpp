/*
** MovableController.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/controller/MovableController/MovableController.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 18 21:16:21 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_MOVABLECONTROLLER_HPP
#define MACRO_ENGINE_MOVABLECONTROLLER_HPP

# include				"macroengine-core/controller/AController/AController.hpp"

namespace				macroengine {
  namespace 				controller {
    namespace 				component {
      /**
       * \class MovableController
       * \brief The controller specialized for the propery::MOVABLE components.
       * This class should not be used by the user.
       */
      class				MovableController : public AController<property::MOVABLE> {
      public:
	MovableController() = default;
	virtual ~MovableController() = default;

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

#endif //MACRO_ENGINE_MOVABLECONTROLLER_HPP
