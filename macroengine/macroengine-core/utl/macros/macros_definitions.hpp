/*
** macros_definitions.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/utl/macros/macros_definitions.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Sat Feb 17 20:20:51 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_MACROS_DEFINITIONS_HPP_
# define MACRO_ENGINE_MACROS_DEFINITIONS_HPP_

# ifndef		MACROENGINE_VAR_DEFAULTS_WINDOW
#  define		MACROENGINE_VAR_DEFAULTS_WINDOW					(true)

#  include		"macros_misc.hpp"

/**
 * Sets the default window title name.
 */
#  define		MACROENGINE_VAR_DEFAULT_WINDOW_TITLE_NAME			"MacroEngine"

/**
 * Sets the default window width.
 */
#  define		MACROENGINE_VAR_DEFAULT_WINDOW_WIDTH				(640)

/**
 * Sets the default window height.
 */
#  define		MACROENGINE_VAR_DEFAULT_WINDOW_HEIGHT				(480)

/**
 * Sets the default value of the fullscreen window feature.
 */
#  define		MACROENGINE_VAR_DEFAULT_WINDOW_FULLSCREEN			(false)
# endif			/* !MACROENGINE_VAR_DEFAULTS_WINDOW */

# ifndef		MACROENGINE_VAR_DEFAULTS_LOCATIONS
#  define		MACROENGINE_VAR_DEFAULTS_LOCATIONS				(true)

/**
 * Sets the default resources directory (can be modified in the main configuration file).
 */
#  define		MACROENGINE_VAR_DEFAULT_RESOURCES_DIRECTORY			"./resources"

/**
 * Sets the default main configuration file. If not precised in the main() function, the Macro Engine will search for this file in the resources directory.
 */
#  define		MACROENGINE_VAR_DEFAULT_CONFIGURATION_FILE			"main_configuration.ini"

/**
 * Sets the default strings file. If not precised in the main() function, the Macro Engine will search for this file in the resources directory.
 */
#  define		MACROENGINE_VAR_DEFAULT_STRINGS_FILE				"strings.ini"
# endif			/* !MACROENGINE_VAR_DEFAULTS_LOCATIONS */

# ifndef		MACROENGINE_VAR_DEFAULTS_VALUES
#  define		MACROENGINE_VAR_DEFAULTS_VALUES					(true)

/**
 * Sets the default Macro Engine core frequency. The Macro Engine will loop for this default value for every script/entity defined by the user.
 */
#  define		MACROENGINE_VAR_DEFAULT_CORE_FREQUENCY				(FPSToSeconds(60))

/**
 * Sets the default Macro Engine identifier system start value (useless for the user).
 */
#  define		MACROENGINE_VAR_DEFAULT_ENTITY_ID_START				(1)
# endif			/* !MACROENGINE_VAR_DEFAULTS_VALUES */

# ifndef		MACROENGINE_VAR_DEBUG_VALUES
#  define		MACROENGINE_VAR_DEBUG_VALUES					(true)

/**
 * Disables all debug modes in the MacroEngine core.
 * @sa the setDebugMode macro
 */
#  define		MACROENGINE_VAR_DEBUG_MODE_NONE					(0)

/**
 * Sets the debug mode to Configuration Only: only the configuration step will be processed; no game loop.
 * @sa the setDebugMode macro
 */
#  define		MACROENGINE_VAR_DEBUG_MODE_CONFIGURATION_ONLY			(1)

# endif			/* !MACROENGINE_VAR_DEBUG_VALUES */

#endif /* !MACRO_ENGINE_MACROS_DEFINITIONS_HPP_ */
