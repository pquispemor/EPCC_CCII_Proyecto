#include "Enemigo.h"

void Enemigo::iniciarVariables() {
    this->conteoPuntos = 50;
    this->tipo = 0;
    this->velocidad = 5.f;
    this->hpMax = 10;
    this->hp = 0;
    this->danio = 1;
    this->puntos = 50;
}

void Enemigo::iniciarForma() {
    this->texture.loadFromFile("Sprites\\Minion1.png");
    this->sprite.setTexture(this->texture);
}

Enemigo::Enemigo(float pos_x, float pos_y)
{
    this->iniciarForma();
    this->iniciarVariables();

    this->sprite.setPosition(pos_x, pos_y);

}

Enemigo::~Enemigo()
{
}


const sf::FloatRect Enemigo::getLimites() const {
    return this->sprite.getGlobalBounds();
}

const int& Enemigo::getPuntos() const {
    return this->puntos;
}

void Enemigo::update() {
    this->sprite.move(0.f, this->velocidad);
}

void Enemigo::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(this->sprite, states);
}