#pragma once
#ifndef MENUCONTROLES_H
#define MENUCONTROLES_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Menu.h"

/*Esta clase solo se encarga de cargar un sprite (.png) y también cuenta el método draw
para hacer que esta clase sea dibujable.*/
class MenuControles : public Menu
{
private:

	void iniciarSprite();
public:
	MenuControles();
	~MenuControles();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
