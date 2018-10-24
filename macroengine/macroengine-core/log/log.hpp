/*
** log.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/log/log.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Jan 24 21:15:16 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_LOG_HPP_
# define MACRO_ENGINE_LOG_HPP_

# include		"macroengine-core/log/Log/Log.hpp"
# include		"macroengine-core/log/Error/Error.hpp"
# include		"macroengine-core/log/Warning/Warning.hpp"
# include		"macroengine-core/log/Dump/Dump.hpp"

using			Warning = macroengine::log::Warning;
using			Log = macroengine::log::Log;
using			Error = macroengine::log::Error;
using			Dump = macroengine::log::Dump;

#endif /* !MACRO_ENGINE_LOG_HPP_ */
