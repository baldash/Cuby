#ifndef				MACROENGINE_GAME_MENUCONTROLLER_HPP_
#define				MACROENGINE_GAME_MENUCONTROLLER_HPP_

# include			<macroengine-core/macroengine-core.hpp>

class				MenuController : public macroengine::property::Controllable {
public:
  MenuController();
  virtual ~MenuController() = default;

  CallableFunction(Escape);
  CallableFunction(Space);
};

#endif				/* !MACROENGINE_GAME_MENUCONTROLLER_HPP_ */
