/*
** namespaces.hpp for Macro_Engine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/utl/namespaces.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Fri May 11 19:11:29 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_NAMESPACES_HPP_
# define MACRO_ENGINE_NAMESPACES_HPP_

/**
 * \namespace macroengine
 * \brief The main namespace the for Macro Engine project.
 * Every class/object refering to the Macro Engine will be stored into this namespace.
 */
namespace				macroengine {
  /**
   * \namespace macroengine::clock
   * \brief Regroups every class or definition in relation with the clock handling or framerate handling and limiting.
   */
  namespace				clock {}

  /**
   * \namespace macroengine::configuration
   * \brief Regroups every class related to the Macro Engine game configuration.
   * It will regroup environment configuration/handling classes, Entity registering classes, strings classes...
   * \sa Every macroengine::configuration class
   */
  namespace 				configuration {

    /**
     * \namespace macroengine::configuration::game
     * \brief Regroups every class related to game configuration.
     * There will be found game, window and misc configuration classes parsing configuration files (see "Configuration files" examples).
     */
    namespace 				game {}

    /**
     * \namespace macroengine::configuration::strings
     * \brief Regroups every class related to strings manipulation, parsing and building.
     * With these classes, the user (and the core) can use pre-built strings.
     * This will allow by the future to change the game language with just a configuration file.
     * @sa "Strings" examples
     */
    namespace 				strings {}
  }

  /**
   * \namespace macroengine::controller
   * \brief Regroups every class related to controller handling.
   * The components updates, the event handling and rendering are processed in classes belonging to this namespace.
   */
  namespace				controller {

    /**
     * \namespace macroengine::controller::component
     * \brief Regroups every class related to the component updating.
     */
    namespace 				component {}

    /**
     * \namespace macroengine::controller::event
     * \brief Regroups every class related to the event handling.
     */
    namespace				event {

      /**
       * \namespace macroengine::controller::event::keyboard
       * \brief Used for misc classes used for the keyboard event handling.
       */
      namespace 			keyboard {}

      /**
       * \namespace macroengine::controller::event::mouse
       * \brief Used for misc classes used for the mouse event handling.
       */
      namespace 			mouse {}
    }
  }

  /**
   * \namespace macroengine::input
   * \brief Namespace used to redirect SFML input systems to ease user access.
   */
  namespace 				input {}

  /**
   * \namespace macroengine::core
   * \brief Namespace containing the core classes. These classes are the base of the Macro Engine and handle the game start, stop and loop processes.
   */
   namespace 				core {}

   /**
    * \namespace macroengine::entity
    * \brief Namespace containing everything related to entities, components, and properties (see examples to make them work).
    */
   namespace				entity {
     /**
      * \namespace macroengine::entity::component
      * \brief Regroups every entity component (Collidable, Controllable...). See examples to know how to use them.
      */
      namespace				component {}
   }

   /**
    * \namespace macroengine::property
    * \brief Regroups every entity property class and enum.
    * The classes are used to set the property bitmask of the central Entity class, and the enums provide values for these properties (see examples).
    */
   namespace 				property {}

   /**
    * \namespace macroengine::exception
    * \brief Regroups every exception thrown in the Macro Engine.
    */
   namespace				exception {}

   /**
    * \namespace macroengine::file
    * \brief Regroups every class related with file handling.
    */
   namespace				file {}

   /**
    * \namespace macroengine::graphics
    * \brief Regroups every Drawable handler (views, sprites, animations....).
    */
   namespace				graphics {

     /**
      * \namespace macroengine::graphics::utl
      * \brief Namespace storing useful classes for graphics and text handlers.
      */
      namespace 			utl {}
   }

   /**
    * \namespace macroengine::log
    * \brief Regroups the log, debug and error displaying classes.
    */
   namespace 				log {}

   /**
    * \namespace macroengine::parser
    * \brief Regroups all the Macro Engine parsers.
    */
   namespace 				parser {

     /**
      * \namespace macroengine::parser::ini
      * \brief Regroups the ini file Macro Engine parser and its useful classes.
      */
     namespace 				ini {}
   }

   /**
    * \namespace macroengine::utl
    * \brief Regroups every utility class, used by several Macro Engine classes from different namespaces of the user.
    */
   namespace 				utl {}
}

#endif /* !MACRO_ENGINE_NAMESPACES_HPP_ */
