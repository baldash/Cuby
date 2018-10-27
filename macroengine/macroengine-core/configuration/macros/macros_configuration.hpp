/*
** macros_configuration.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/configuration/macros/macros_configuration.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Tue Feb 13 23:28:58 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_MACROS_CONFIGURATION_HPP_
# define MACRO_ENGINE_MACROS_CONFIGURATION_HPP_

# include		"macroengine-core/core/global/g_core.hpp"
# include		"macroengine-core/configuration/static/build_instance.hpp"
# include		"macros_callable.hpp"
# include		"macroengine-core/configuration/static/find_entity.hpp"
# include		"macroengine-core/utl/macros/macros_definitions.hpp"

/**
 * \def setEnvironment(AC, AV, AE)
 * sets the environment using the main function parameters.
 * @param AC first main function parameter
 * @param AV second main function parameter
 * @param AE third main function parameter
 * @sa macroengine::configuration::Environment class
 */
# ifndef		MACROENGINE_SET_ENVIRONMENT
#  define		setEnvironment(AC, AV, AE)		g_core.getConfiguration().getEnvironment().set(AC, AV, AE)
# endif			/* !MACROENGINE_SET_ENVIRONMENT */

/**
 * \def setMainConfigurationFile(F)
 * Sets the environment using the main function parameters.
 * This will work until the runEngine macro is called.
 * @param F the path to the configuration file
 * @sa macroengine::configuration::Configuration class
 */
# ifndef		MACROENGINE_SET_MAIN_CONFIGURATION_FILE
#  define		setMainConfigurationFile(F)		g_core.getConfiguration().setConfigurationFile(F)
# endif			/* !MACROENGINE_SET_MAIN_CONIG_FILE */

/**
 * \def registerEntity(ID, TYPE)
 * registers the entity to the EntityRegister class instance.
 * @param ID the entity name (std::string)
 * @par TYPE the entity class
 * @sa macroengine::configuration::EntityRegister class
 */
# ifndef		MACROENGINE_REGISTER_ENTITY
#  define		registerEntity(ID, TYPE)		g_core.getConfiguration().getEntityRegister().add(ID, &build_instance<TYPE>)
# endif			/* !MACROENGINE_REGISTER_ENTITY */

/**
 * \def enableEntityAtLaunch(ID)
 * enables entity at launch using the EntityRegister class instance.
 * @param ID the entity name (std::string)
 * @sa macroengine::configuration::EntityRegister class
 */
# ifndef		MACROENGINE_ENABLE_ENTITY_AT_LAUNCH
#  define		enableEntityAtLaunch(ID)		g_core.getConfiguration().getEntityRegister().enableAtLaunch(ID)
# endif			/* !MACROENGINE_ENABLE_ENTITY_AT_LAUNCH */

/**
 * \def runEngine
 * runs the engine.
 * @sa macroengine::core::Core class
 */
# ifndef		MACROENGINE_RUN_ENGINE
#  define		runEngine				g_core.run
# endif			/* !MACROENGINE_RUN */

/**
 * \def stopEngine
 * stops the engine.
 * @sa macroengine::core::Core class
 */
# ifndef		MACROENGINE_STOP_ENGINE
#  define		stopEngine				g_core.stop
# endif			/* !MACROENGINE_STOP */

/**
 * \def Environment
 * redirection to the Environment class instance.
 * @sa macroengine::configuration::Environment
 */
# ifndef		MACROENGINE_ENVIRONMENT
#  define		Environment				g_core.getConfiguration().getEnvironment().getAsConst()
# endif			/* !MACROENGINE_ENVIRONMENT */

/**
 * \def MainConfiguration
 * redirection to the MainConfiguration class instance.
 * @sa macroengine::configuration::MainConfiguration
 */
# ifndef		MACROENGINE_MAIN_CONFIGURATION
#  define		MainConfiguration			g_core.getConfiguration().getGameConfiguration().getAsConst()
# endif			/* !MACROENGINE_MAIN_CONFIGURATION */

/**
 * \def Clock
 * redirection to the Clock class instance of the Core class.
 * @sa macroengine::clock::Clock
 */
# ifndef		MACROENGINE_CORE_CLOCK
#  define		CoreClock				g_core.getClock()
# endif			/* !MACROENGINE_CORE_CLOCK */

/**
 * \def EntityIDGenerator
 * redirection to the EntityIDGenerator class instance.
 * @sa macroengine::configuration::EntityIDGenerator
 */
# ifndef		MACROENGINE_ENTITY_ID_GENERATOR
#  define		EntityIDGenerator			g_core.getConfiguration().getEntityIDGenerator()
# endif			/* !MACROENGINE_ENTITY_ID_GENERATOR */

/**
 * \def findInResourcesDirectory(P)
 * returns the path of the file \a P concatenated to the resources directory.
 * @param P the file path, relative to the resources directory whatever it is
 * @sa macroengine::configuration::Environment
 */
# ifndef		MACROENGINE_FIND_IN_RESOURCES_DIR
#  define		findInResourcesDirectory(P)		std::string(Environment.getResourcesDirectory() + "/" + P)
# endif			/* !MACROENGINE_FIND_IN_RESOURCES_DIR */

/**
 * \def setDebugMode(M)
 * sets the debug mode of the MacroEngine core (refer to macros_definitions.hpp for the possible values).
 * @param M the debug mode
 */
# ifndef		MACROENGINE_SET_DEBUG_MODE
#  define		setDebugMode(M)				g_core.setCoreDebugMode(M)
# endif			/* !MACROENGINE_SET_DEBUG_MODE */

#endif /* !MACRO_ENGINE_MACROS_CONFIGURATION_HPP_ */
