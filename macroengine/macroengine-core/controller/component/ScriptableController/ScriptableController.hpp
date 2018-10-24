/*
** ScriptableController.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/controller/component/ScriptableController/ScriptableController.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Mar 01 22:19:29 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_SCRIPTABLECONTROLLER_HPP
#define MACRO_ENGINE_SCRIPTABLECONTROLLER_HPP

# include				"macroengine-core/controller/AController/AController.hpp"

namespace				macroengine {
  namespace 				controller {
    namespace 				component {
      /**
       * \class ScriptableController
       * \brief The controller specialized for the propery::SCRIPTABLE components.
       * This class should not be used by the user.
       */
      class				ScriptableController : public AController<property::SCRIPTABLE> {
      private:
	t_animations			_animations;

      public:
	ScriptableController() = default;
	virtual ~ScriptableController() = default;

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

#endif //MACRO_ENGINE_SCRIPTABLECONTROLLER_HPP
