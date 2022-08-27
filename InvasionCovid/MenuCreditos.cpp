#include "MenuCreditos.h"
/*Esta clase solo se encarga de cargar un sprite (.png) y también cuenta el método draw
para hacer que esta clase sea dibujable.*/
void MenuCreditos::iniciarSprite()
{
	this->textura.loadFromFile("Fondos\\MenuCreditos.png");
	this->fondo.setTexture(this->textura);
}

MenuCreditos::MenuCreditos()
{
	this->iniciarSprite();
}

MenuCreditos::~MenuCreditos()
{
}

void MenuCreditos::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->fondo, states);
}
