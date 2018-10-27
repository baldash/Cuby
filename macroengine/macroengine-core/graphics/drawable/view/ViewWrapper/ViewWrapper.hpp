/*
** ViewWrapper.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/drawable/view/ViewWrapper/ViewWrapper.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Apr 13 18:52:09 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_VIEWWRAPPER_HPP
#define MACRO_ENGINE_VIEWWRAPPER_HPP

# include				"macroengine-core/entity/property/enum/e_subproperty.hpp"
# include				"macroengine-core/graphics/drawable/ADrawableHandler/ADrawableHandler.hpp"
# include				"macroengine-core/utl/Dimensions/Dimensions.hpp"
# include				"macroengine-core/utl/types.hpp"
# include				"macroengine-core/graphics/drawable/view/View/View.hpp"

namespace 				macroengine {
  namespace 				graphics {
    /**
     * \class ViewWrapper
     * \brief This class is used to handle multiple views and provides a container to store every known view for the created entity.
     */
    class				ViewWrapper : public ADrawableHandler, public Object {
    private:
      t_views				_views;

    public:
      ViewWrapper();
      virtual ~ViewWrapper() = default;

      virtual void			dump() override;

      /**
       * Adds a view.
       * @param name the view name
       * @param width the view width
       * @param height the view height
       * @return a reference on the new created View
       */
      View				&add(std::string const &name = "", size_t width = 0, size_t height = 0);

      /**
       * Adds a view
       * @param name the view name
       * @param dim the view dimensions
       * @return a reference on the new created View
       */
      View				&add(std::string const &name = "", macroengine::utl::Dimensions const &dim = macroengine::utl::Dimensions(0, 0));

      /**
       * Gets a View, given its identifier (id, name or both).
       * If no item matches, it throws a exception::UnknownViewIDException or a exception::UnknownViewNameException depending on the identifier content.
       * @param identifier the identifier
       * @return a reference on the found View
       */
      View				&get(t_identifier const &identifier);

      /**
       * Removes a view given its identifier (id, name or both).
       * @param identifier the identifier
       */
      void				remove(t_identifier const &identifier);

      /**
       * Gets all the created views.
       * @return a t_views reference
       */
      t_views				&getAll();

    private:
      View				&get(std::string const &name);
      View				&get(t_entity_id const &id);

      void				remove(std::string const &name);
      void				remove(t_entity_id const &id);
    };
  }
}

#endif //MACRO_ENGINE_VIEWWRAPPER_HPP
