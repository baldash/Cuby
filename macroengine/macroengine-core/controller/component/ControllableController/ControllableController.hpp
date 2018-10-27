/*
** ControllableController.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/controller/ControllableController/ControllableController.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 18 21:16:21 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_CONTROLLABLECONTROLLER_HPP
#define MACRO_ENGINE_CONTROLLABLECONTROLLER_HPP

# include				"macroengine-core/controller/AController/AController.hpp"

namespace				macroengine {
  namespace 				controller {
    namespace 				component {
      /**
       * \class ControllableController
       * \brief The controller specialized for the propery::CONTROLLABLE components.
       * This class should not be used by the user.
       */
      class				ControllableController : public AController<property::CONTROLLABLE> {
      public:
  	ControllableController() = default;
	  virtual ~ControllableController() = default;

	/**
	 * initialization method, called by the GeneralController
	 * @return 0 if OK, 1 otherwise
	 */
	virtual void			dump() override;

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

#endif //MACRO_ENGINE_CONTROLLABLECONTROLLER_HPP
