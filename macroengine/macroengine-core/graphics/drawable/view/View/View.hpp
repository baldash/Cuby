/*
** View.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/graphics/drawable/view/View/View.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri Apr 13 18:56:04 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_VIEW_HPP
#define MACRO_ENGINE_VIEW_HPP

# include					<SFML/Graphics.hpp>
# include					"macroengine-core/Object/Object.hpp"
# include					"macroengine-core/utl/Position/Position.hpp"

namespace 					macroengine {
  namespace 					graphics {
    /**
     * \class View
     * \brief The sf::View wrapper, allowing the user to create Macro Engine compatible views around Drawable entities.
     * See the examples on how to handle this class.
     */
    class					View : public Object {
    private:
      /**
       * \enum ratios
       * \brief Sets some values to use them in a float array, instead of using confusing array numbers directly.
       */
      enum					ratios {
	VIEW_RATIOS_X				= 0,
	VIEW_RATIOS_Y				= 1,
	VIEW_RATIOS_WIDTH			= 2,
	VIEW_RATIOS_HEIGHT			= 3,
	VIEW_RATIOS				= 4
      };

    private:
      sf::View					_view;
      macroengine::utl::Dimensions		_dimensions;
      t_bound_elements				_bound_elements;
      float					_ratios[VIEW_RATIOS];

    public:
      View();
      virtual ~View() = default;

      virtual void				dump() override;

      /**
       * Initializes the view after setting its dimensions/position.
       * @return 0 if OK, 1 otherwise
       */
      int					init();

      /**
       * Sets the view dimensions.
       * @param dimensions the dimensions
       * @return a reference on itself
       */
      View					&setDimensions(macroengine::utl::Dimensions const &dimensions);

      /**
       * Gets the view dimensions.
       * @return the dimensions
       */
      macroengine::utl::Dimensions const	&getDimensions();

      /**
       * Gets all bound elements.
       * @return a t_bound_elements const reference
       */
      t_bound_elements const			&getAllBoundElements();

      /**
       * Removes a bound element given its identifier (id, name or both).
       * @param identifier the identifier
       * @return a reference on itself
       */
      View					&removeBoundElement(t_identifier const &identifier);

      /**
       * Gets the created sf::View. This method should be reserved to the Macro Engine core.
       * @return a reference on the sf::View
       */
      sf::View					&getView();

      /**
       * Sets the viewport height ratio (see examples / SFML documentation).
       * @return a reference on itself
       */
      View					&setViewHeightRatio(float ratio);

      /**
       * Sets the viewport width ratio (see examples / SFML documentation).
       * @return a reference on itself
       */
      View					&setViewWidthRatio(float ratio);

      /**
       * Sets the viewport x position ratio (see examples / SFML documentation).
       * @return a reference on itself
       */
      View					&setViewXPositionRatio(float ratio);

      /**
       * Sets the viewport y position ratio (see examples / SFML documentation).
       * @return a reference on itself
       */
      View					&setViewYPositionRatio(float ratio);

      /**
       * Binds an Drawable element to the view, given its identifier (both id and name are required here).
       * @param elem the element identifier
       * @param prop its Drawable subproperty
       * @return a reference on itself
       */
      View					&bindElement(t_identifier const &elem, property::e_subproperty prop);

      /**
       * Checks whether an element is bound or not
       * @param identifier the element identifier (id, name or both)
       * @param the element Drawable subproperty
       * @return true if this element is bound, false otherwise
       */
      bool					isElementBound(t_identifier const &identifier, property::e_subproperty prop);

      /**
       * Moves the view to a given position.
       * @param pos the position
       * @return a reference on itself
       */
      View					&move(macroengine::utl::Position const &pos);

    private:
      View					&removeBoundElement(t_entity_id const &id);
      View					&removeBoundElement(std::string const &name);
      View					&setViewRatio(float ratio, ratios id);
    };
  }
}

#endif //MACRO_ENGINE_VIEW_HPP
