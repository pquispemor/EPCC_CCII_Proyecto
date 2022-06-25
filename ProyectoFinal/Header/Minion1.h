#ifndef MINION1_H
#define MINION1_H

#include <SFML\Graphics.hpp>

class Minion1: public sf::Drawable
{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    int tipo;
    float velocidad;
    int hp;
    int hpMax;
    int danio;
    int puntos;

    void iniciarForma();
    void iniciarVariables();

public:
    Minion1(float pos_x, float pos_y);
    ~Minion1();

    //*Accesorio
    const sf::FloatRect getLimites() const;

    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

void Minion1::iniciarForma(){
    this->texture.loadFromFile("Sprites\\Minion1.png");
    this->sprite.setTexture(this->texture);
}

void Minion1::iniciarVariables(){
    this->tipo = 0;
    this->velocidad = 5.f;
    this->hpMax = 10;
    this->hp = 0;
    this->danio = 1;
    this->puntos = 5;
}

Minion1::Minion1(float pos_x, float pos_y)
{
    this->iniciarForma();
    this->iniciarVariables();

    this->sprite.setPosition(pos_x, pos_y);

}

Minion1::~Minion1()
{
}


const sf::FloatRect Minion1::getLimites() const{
    return this->sprite.getGlobalBounds();
}

void Minion1::update(){
    this->sprite.move(0.f,this->velocidad);
}

void Minion1::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(this->sprite,states);   
}

#endif