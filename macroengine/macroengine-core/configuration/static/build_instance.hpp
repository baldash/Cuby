/*
** build_instance.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/entity/registering/static/build_instance.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Feb 08 10:41:35 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_BUILD_INSTANCE_HPP
# define MACRO_ENGINE_BUILD_INSTANCE_HPP

# include			"macroengine-core/entity/Entity/Entity.hpp"

/**
 * \static build_instance
 * returns a pointer to a newly created Entity-inherited class given as template parameter.
 * @tparam T the user-defined entity, inheriting from macroengine::Entity (see the examples for more info about this inheritance)
 * @return a pointer to the newly allocated memory
 */
template<typename T>
macroengine::entity::Entity	*build_instance() {
  return new T();
}

#endif /* !MACRO_ENGINE_BUILD_INSTANCE_HPP */
