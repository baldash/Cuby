/*
** AController.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/controller/GeneralController/AController/AController.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Feb 18 20:43:13 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_ACONTROLLER_HPP
#define MACRO_ENGINE_ACONTROLLER_HPP

# include				"macroengine-core/Object/Object.hpp"
# include				"macroengine-core/entity/property/enum/e_property.hpp"
# include				"macroengine-core/utl/types.hpp"

namespace 				macroengine {
  namespace 				controller {

    /**
     * \class AController
     * \brief The abstraction for every Macro Engine controller. Every controller controls and updates a specific Entity component (see the examples)
     * @tparam Type the e_property value of the controller components (see the examples)
     */
    template<property::e_property Type>
    class				AController : public Object {
    public:
      AController() = default;
      virtual ~AController() = default;

      /**
       * NOT YET USED
       * @return
       */
      virtual int			stop() = 0;

      /**
       * Called by the GeneralController. Updates the entities matching the \a Type value.
       * @param entities The entities matching the \a Type value
       * @param total Every created entity registered in the GeneralController
       * @return 0 if OK, 1 otherwise
       */
      virtual int			update(configuration::t_built_entities &entities, configuration::t_built_entities &total) = 0;
    };
  }
}

#endif //MACRO_ENGINE_ACONTROLLER_HPP
