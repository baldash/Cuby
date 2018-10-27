/*
** ShapeWrapper.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/drawable/shape/ShapeWrapper/ShapeWrapper.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Mon Mar 19 11:26:22 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_SHAPEWRAPPER_HPP
#define MACRO_ENGINE_SHAPEWRAPPER_HPP

# include				"macroengine-core/utl/types.hpp"
# include				"macroengine-core/graphics/drawable/shape/RectangleShape/RectangleShape.hpp"
# include				"macroengine-core/graphics/drawable/ADrawableHandler/ADrawableHandler.hpp"
# include				"macroengine-core/Object/Object.hpp"

namespace 				macroengine {
  namespace				graphics {
    /**
     * \class ShapeWrapper
     * \brief This class is used to handle multiple shapes and provides a container to store every known shape for the created entity.
     */
    class				ShapeWrapper : public ADrawableHandler, public Object {
    private:
      t_rectangle_shapes		_rectangle_shapes;

    public:
      ShapeWrapper();
      virtual ~ShapeWrapper() = default;

      virtual void dump() override;

      /**
       * Adds a rectangle shape to the container.
       * @param name the shape name
       * @return a reference on the created empty RectangleShape
       */
      RectangleShape			&addRectangleShape(std::string const &name = "");

      /**
       * Removes a RectangleShape gicven its identifier (id, name or both).
       * @param identifier the identifier
       */
      void				removeRectangleShape(t_identifier const &identifier);

      /**
       * Gets all the created rectangle shapes.
       * @return a t_regtangle_shapes reference
       */
      t_rectangle_shapes		&getRectangleShapes();

    private:
      void				removeRectangleShape(t_entity_id const &id);
      void				removeRectangleShape(std::string const &name);
    };
  }
}

#endif //MACRO_ENGINE_SHAPEWRAPPER_HPP
