/*
** ADrawableHandler.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/drawable/ADrawableHandler/ADrawableHandler.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Mar 16 10:58:45 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_ADRAWABLEHANDLER_HPP
#define MACRO_ENGINE_ADRAWABLEHANDLER_HPP

namespace 				macroengine {
  namespace 				graphics {
    /**
     * \class ADrawableHandler
     * \brief The abstraction for all the Drawable handlers present in macroengine::graphics.
     */
    class				ADrawableHandler {
    private:
      bool				_enabled;

    public:
      ADrawableHandler();
      virtual ~ADrawableHandler() = default;

      /**
       * Enables the handler.
       */
      void				enable();

      /**
       * Disables the handler.
       */
      void				disable();

      /**
       * Checks whether the handler is enabled or not.
       * @return true is enabled, false otherwise
       */
      bool				enabled();
    };
  }
}

#endif //MACRO_ENGINE_ADRAWABLEHANDLER_HPP
