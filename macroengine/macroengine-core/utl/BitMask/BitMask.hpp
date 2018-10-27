/*
** BitMask.hpp for macroengine in /home/sylvain/Documents/projets/perso/C++/macroengine/macroengine/utl/BitMask.hpp
**
** Made by Sylvain CHAUGNY
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Wed Jan 24 21:04:01 2018 Sylvain CHAUGNY
*/

#ifndef MACRO_ENGINE_BITMASK_HPP_
# define MACRO_ENGINE_BITMASK_HPP_

# include			"macroengine-core/Object/Object.hpp"

namespace			macroengine {
  namespace			utl {
    /**
     * \class BitMask
     * \brief A bitmask wrapper, to avoid making bit shifts every inside the Entity-based classes.
     */
    class			BitMask : public Object {
    private:
      std::size_t		_mask;

    public:
      BitMask();

      /**
       * This constructor directly takes the mask as parameter.
       * @param mask The mask
       */
      BitMask(size_t const &mask);

      /**
       * Copy constructor.
       * @param obj another BitMask class
       */
      BitMask(BitMask const &obj);
      virtual ~BitMask() = default;

      virtual void		dump() override;

      /**
       * Sets the content of itself from the other BitMask class.
       * @param obj the other BitMask class
       * @return a reference on itself
       */
      BitMask			&operator=(BitMask const &obj);

      /**
       * Adds a value to its mask
       * @param nb the value (should be a power of 2)
       */
      void			operator+=(size_t nb);

      /**
       * Checks whether its mask contains the given value or not.
       * @param nb the asked value (should be a power of 2)
       * @return true if the value is found, false otherwise
       */
      bool			contains(size_t nb) const;

      /**
       * Adds a value to its mask
       * @param nb the value (should be a power of 2)
       */
      void			add(size_t nb);
    };
  }
}

#endif /* !MACRO_ENGINE_BITMASK_HPP_ */
