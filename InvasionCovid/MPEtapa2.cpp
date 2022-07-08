#include "MPEtapa2.h"


void MPEtapa2::iniciarInterfaz()
{
	this->texture.loadFromFile("Fondos\\Fase1.png");
	fondo.setTexture(this->texture);
}

MPEtapa2::MPEtapa2()
{
	this->iniciarInterfaz();
}

MPEtapa2::~MPEtapa2()
{
}

void MPEtapa2::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(this->fondo, states);
}