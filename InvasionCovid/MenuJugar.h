#pragma once
#ifndef MENUJUGAR_H
#define MENUJUGAR_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Menu.h"
/*Dentro del MenúJugar solo encontraremos métodos como cargar un sprite (.png) asi
como también cargar string (opciones 1 Jugador y 2 Jugadores) y por último el método
draw que sirve para que esta clase pueda ser dibujada.*/
class MenuJugar : public Menu
{
private:
	void iniciarSprite();
public:
	MenuJugar();
	~MenuJugar();
	void MoverArriba();
	void MoverAbajo();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
