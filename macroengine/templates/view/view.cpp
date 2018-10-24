//
// view.cpp for view in /home/sylvain/macroengine/templates
//
// Made by Sylvain Chaugny
// Login   <sylvain.chaugny@epitech.eu>
//
// Started on  Wed Apr  4 14:25:16 2018 Sylvain Chaugny
// Last update Thu May 10 00:10:35 2018 Sylvain Chaugny
//


#include <unistd.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
  sf::RenderWindow win(sf::VideoMode(800, 600), "coucou");

  sf::Texture tex;

  tex.loadFromFile("./test.jpg");
  sf::Sprite sprite1(tex);

  sf::Texture tex2;
  tex2.loadFromFile("./test.jpg");
  sf::Sprite sprite2(tex2);

  sf::View view1;
  sf::View view2;

  // view1 = sf::View([centre de la view, depuis le milieu], [taille]);
  // avec [400, 300] en centre, la view apparaitra comme la view par défaut
  // avec [0, 0], le centre de la view sera en [0, 0], donc seule une partie de la view sera affichée

  // setviewport : sf::FloatRect(ratio du point de départ en x par rapport a la fenetre,
  //				 ratio du point de départ en y par rapport a la fenetre,
  //				 ratio de la longueur par rapport a la fenetre
  //				 ratio de la largeur par rapport a la fenetre


  view1 = sf::View(sf::Vector2f(400, 300), sf::Vector2f(800, 600));
  view1.setViewport(sf::FloatRect(0.25f, 0.25f, 0.75, 0.75));

  view2.setCenter(400, 300);
  view2.setSize(800, 600);

  win.setFramerateLimit(60);

  while (1)
    {
      sf::Event event;
      win.clear();
      while (win.pollEvent(event))
	{
	  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
	    {
	      win.close();
	      return 0;
	    }
	}
      view1.move(10, 10);
      win.setView(view1);
      win.draw(sprite1);

      // win.setView(view2);
      // win.draw(sprite2);
      win.display();
    }
  return (0);
}
