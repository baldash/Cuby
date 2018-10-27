/*
** AnimationWrapper.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/AnimationWrapper/AnimationWrapper.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sun Mar 11 20:16:32 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_ANIMATIONWRAPPER_HPP
#define MACRO_ENGINE_ANIMATIONWRAPPER_HPP

# include				<unordered_map>
# include				"macroengine-core/graphics/drawable/ADrawableHandler/ADrawableHandler.hpp"
# include				"macroengine-core/Object/Object.hpp"
# include				"macroengine-core/graphics/drawable/animation/Animation/Animation.hpp"
# include				"macroengine-core/utl/types.hpp"

namespace 				macroengine {
  namespace 				graphics {
    /**
     * \class AnimationWrapper
     * \brief This class is used to handle multiple animations and provides a container to store every known animation for the created entity.
     */
    class				AnimationWrapper : public ADrawableHandler, public Object {
    private:
      t_animations 			_animations;
      t_identifier			_current_animation;

    public:
      AnimationWrapper();
      virtual ~AnimationWrapper() = default;

      virtual void 			dump() override;

      /**
       * Adds a new animation loading it from a .ini file.
       * @param name the animation name
       * @param ini the .ini path
       * @return a reference on the created animation
       */
      Animation				&addFromIni(std::string const &name, std::string const &ini);

      /**
       * Gets the current animation.
       * @return a reference on the current animation
       */
      Animation				&getCurrentAnimation();

      /**
       * Checks whether any animation is selected or not.
       */
      bool				isAnyAnimationSelected();

      /**
       * Sets the current animation.
       * @param identifier the animation identifier (id, name or both)
       * @return a reference on the new current animation
       */
      Animation				&setCurrentAnimation(t_identifier const &identifier);

      /**
       * Gets an animation given its identifier (id, name or both).
       * If no animation is found, this throws a exception::UnknownAnimationIDException or a exception::UnknownAnimationNameException
       * (depending on the identifier content).
       * @param identifier the identifier
       * @return a reference on the found animation
       */
      Animation				&get(t_identifier const &identifier);

      /**
       * Gets all created animations.
       * @return a reference on the animation array
       */
       t_animations 			&getAll();

      /**
       * Removes an animation given its identifier (id, name or both).
       * @param identifier the identifier
       */
      void				remove(t_identifier const &identifier);

    private:
      Animation				&get(std::string const &name);
      Animation				&get(t_entity_id const &id);

      void				remove(t_entity_id const &id);
      void				remove(std::string const &name);

      void				setCurrentAnimation(t_entity_id const &id);
      void				setCurrentAnimation(std::string const &name);
    };
  }
}

#endif //MACRO_ENGINE_ANIMATIONWRAPPER_HPP
