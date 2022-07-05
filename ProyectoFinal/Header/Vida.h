#ifndef VIDA_H
#define VIDA_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Vida : public sf::Drawable
{
private:
    sf::Sprite spriteVida;
    sf::Texture textureVida;
    void iniciarForma();
public:
    Vida(float pos_x, float pos_y);
    ~Vida();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

void Vida::iniciarForma(){
    this->textureVida.loadFromFile("Sprites\\Vida.png");
    this->spriteVida.setTexture(this->textureVida);
}

Vida::Vida(float pos_x, float pos_y)
{
    this->iniciarForma();
    this->spriteVida.setPosition(pos_x, pos_y);
}

Vida::~Vida()
{
}

void Vida::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(this->spriteVida,states);   
}

#endif