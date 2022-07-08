#pragma once
#ifndef MPETAPA2_H
#define MPETAPA2_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class MPEtapa2 : public sf::Drawable
{
private:
	sf::Sprite fondo;
	sf::Texture texture;
	void iniciarInterfaz();
public:
	MPEtapa2();
	~MPEtapa2();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

#endif