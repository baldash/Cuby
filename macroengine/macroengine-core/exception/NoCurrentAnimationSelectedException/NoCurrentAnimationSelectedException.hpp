/*
** NoCurrentAnimationSelectedException.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/exception/NoCurrentAnimationSelectedException/NoCurrentAnimationSelectedException.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu Mar 01 23:29:11 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_NOCURRENTACTIVITYSELECTEDEXCEPTION_HPP
#define MACRO_ENGINE_NOCURRENTACTIVITYSELECTEDEXCEPTION_HPP

# include				<exception>
# include				<string>

namespace 				macroengine {
  namespace 				exception {
    /**
     * \class NoCurrentAnimationSelectedException
     * \brief Exception thrown when the animation handlers try to access an inexisting current animation.
     */
    class				NoCurrentAnimationSelectedException : public std::exception {
    private:
      std::string			_what;

    public:
      explicit NoCurrentAnimationSelectedException(std::string const &str) noexcept;
      virtual ~NoCurrentAnimationSelectedException() = default;

      const char		*what() const throw();
    };
  }
}

#endif //MACRO_ENGINE_NOCURRENTACTIVITYSELECTEDEXCEPTION_HPP
