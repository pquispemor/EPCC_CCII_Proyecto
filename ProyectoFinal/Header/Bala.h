#ifndef BALA_H
#define BALA_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Bala: public sf::Drawable
{
private:
    sf::Sprite shape;

    sf::Vector2f direccion;
    float moveSpeed;
public:
    Bala();
    Bala(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float moveSpeed);
    ~Bala();

    //*Accesorio
    const sf::FloatRect getLimites() const;

    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

Bala::Bala(){}

Bala::Bala(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float moveSpeed) 
{
    this->shape.setTexture(*texture);

    this->shape.setPosition(pos_x - 5, pos_y - 30);
    this->direccion.x = dir_x;
    this->direccion.y = dir_y;
    this->moveSpeed = moveSpeed;
}

Bala::~Bala()
{
}

const sf::FloatRect Bala::getLimites() const{
    return this->shape.getGlobalBounds();
}

void Bala::update(){
    //* Movimiento de la bala
    this->shape.move(this->moveSpeed * this->direccion);
}

void Bala::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(this->shape,states);   
}

#endif
