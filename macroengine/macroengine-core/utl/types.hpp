/*
** types.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/utl/types.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sat Apr 14 20:57:00 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_TYPES_HPP_
# define MACRO_ENGINE_TYPES_HPP_

# include			<functional>
# include			<vector>
# include			<memory>
# include			<string>
# include			<map>
# include			<unordered_map>
# include			<SFML/Graphics/Color.hpp>
# include			"macroengine-core/entity/property/enum/e_property.hpp"
# include			"macroengine-core/entity/property/enum/e_subproperty.hpp"
# include			"macroengine-core/utl/struct/CallableData/CallableData.hpp"
# include			"macroengine-core/utl/struct/s_identifier/s_identifier.hpp"
# include			<SFML/Window/Keyboard.hpp>
# include			<SFML/Window/Mouse.hpp>

namespace 			macroengine {
  namespace 			entity {
    class			Entity;
  }

  namespace 			utl {
    class			BitMask;
    class			Position;
  }

  namespace 			input {

    /**
     * Redirection to the SFML Keyboard::Key system, to ease user accessing.
     */
    using			Keyboard = sf::Keyboard::Key;

    /**
     * Redirection to the SFML Mouse::Button system, to ease user accessing.
     */
    using			MouseButton = sf::Mouse::Button;

    /**
     * Redirection to the SFML Mouse::Wheel system, to ease user accessing.
     */
    using			MouseWheel = sf::Mouse::Wheel;
  }

  using				t_entity_id = long;
  using				t_identifier = utl::s_identifier;

  namespace 			clock {

    class			Time;
    class			Clock;

    /**
     * using t_delay_id instead of int is much more practical and readable.
     */
    using			t_delay_id = int;

    using			t_time_delay = Time;
    using			t_time_offset = Time;
    using			t_offsets = std::map<t_delay_id, std::pair<t_time_offset, t_time_delay>>;
  }

  namespace			file {
    using			t_raw_content = std::vector<std::string>;
    using			t_raw_content_i = std::vector<std::string>::iterator;
    using			t_raw_content_ci = std::vector<std::string>::const_iterator;
  }

  namespace 			configuration {
    using			t_builder = entity::Entity *(*)();
    using			t_built_entity = std::shared_ptr<entity::Entity>;
    using			t_built_entities = std::map<t_identifier, t_built_entity>;

    /**
     * used to ease the access to the builders array.
     */
    using			t_register = std::map<t_identifier, t_builder>;

    /**
     * used to set whether the entities are enabled at launch or not.
     */
    using			t_enabled_at_launch = std::map<t_identifier, int>;

    namespace 			strings {
      class			StringBuilder;
      class			StringContent;

      /**
       * this eases the t_flags manipulation.
       */
      using			t_flag = std::pair<std::string, void (StringBuilder::*)(std::string &, va_list &)>;

      /**
       * allows the StringBuilder to rely on a member function pointer array to detect the strings flags (%d, %s, %cs, %ld...).
       * @sa the "Strings" examples
       */
      using			t_flags = std::vector<t_flag>;

      using			t_strings = std::map<std::string, StringContent>;
    }
  }

  namespace			entity {
    using			t_subproperties = std::map<property::e_property, utl::BitMask>;

    namespace 			component {
      class			ScriptableCallableParams;

      /**
       * The t_callables array is used to sort the created scripts by their identifier.
       */
      using			t_callables = std::map<t_identifier, component::ScriptableCallableParams>;
    }
  }

  namespace 			graphics {
    class			View;
    class			Animation;
    class			Sprite;
    class			RectangleShape;
    class			Text;

    namespace 			utl {
      class			TextEntry;
      class			FontEntry;
    }

    using			t_text_entries = std::map<t_entity_id, utl::TextEntry>;
    using			t_font_entries = std::map<t_entity_id, utl::FontEntry>;
    using			Color = sf::Color;

    /**
     * The t_animations map is used to sort the animations by their t_identifier.
     */
    using				t_animations = std::map<t_identifier, Animation>;

    /**
     * The t_sprites map stored the created Sprite by their t_identifier.
     */
    using				t_sprites = std::map<t_identifier, Sprite>;

    /**
     * The t_rectangle_shapes stores every user-defined rectangle shape in this class.
     */
    using				t_rectangle_shapes = std::map<t_identifier, RectangleShape>;

    /**
     * The t_views is used to store created View classes by their identifier.
     */
    using				t_views = std::map<t_identifier, View>;

    /**
     * The t_texts is used to store created Text classes by their identifier.
     */
    using				t_texts = std::map<t_identifier, Text>;

    using				t_bound_elements = std::map<t_identifier, std::vector<property::e_subproperty>>;
  }

  namespace 			controller {
    using			t_callable = std::function<void(configuration::t_built_entities &, utl::CallableData const &)>;
    using			t_action = std::pair<t_callable, std::pair<t_entity_id, clock::t_delay_id>>;
    using			t_controller_data = std::vector<t_action>;

    /**
     * The t_sorted_entities map is used to sort the entities by theirs e_property.
     * This will ease the controller update process.
     * \sa macroengine::controller classes
     */
    using 			t_sorted_entities = std::map<property::e_property, configuration::t_built_entities>;

    /**
     * The t_views type lists every defined view. This map will be used to access the views in every update method in the class.
     */
    using			t_views = std::map<t_identifier, graphics::View>;

    /**
     * The first field of the t_mouse_position is used to check whether the mouse position has changed since the last update.
     * The second field stores this position.
     */
    using			t_mouse_position = std::pair<bool, utl::Position>;

    namespace			event {
      namespace 		keyboard {
        class			KeyboardActionParams;

	/**
	 * The t_keyboard_data is the map of keys, associated to the known actions for each of them.
	 */
	using			t_keyboard_data = std::map<::macroengine::input::Keyboard, std::vector<keyboard::KeyboardActionParams>>;
      }

      namespace 		mouse {
	class			MouseActionParams;

	/**
	 * The t_mouse_button_data is the map of button keys, associated to the known actions for each of them.
	 */
	using			t_mouse_button_data = std::map<::macroengine::input::MouseButton, std::vector<mouse::MouseActionParams>>;

	/**
	 * The t_mouse_move_data lists every known mouse move action added by the user.
	 * This should be modified by the future to match the MouseButtonData and KeyboardData classes.
	 */
	using			t_mouse_move_data = std::vector<MouseActionParams>;
      }

    }

    namespace 			component {
      using			t_animations = std::vector<configuration::t_built_entity>;
    }
  }

  namespace 			parser {
    namespace 			ini {

      class			IniScope;

      /**
       * The t_ini_scope map stores the key-value system of the parsed scope.
       */
      using			t_ini_scope = std::unordered_map<std::string, std::string>;

      using			t_entry = std::pair<std::string, std::string>;
      using			t_scope_content = std::unordered_map<std::string, IniScope>;
    }
  }

  using				Clock = macroengine::clock::Clock;
  using				Time = macroengine::clock::Time;
}

#endif /* !MACRO_ENGINE_TYPES_HPP_ */
