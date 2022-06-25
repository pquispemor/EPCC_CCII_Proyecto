#ifndef JUGADOR1_H
#define JUGADOR1_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Jugador1: public sf::Drawable
{
private:
    sf::Sprite sprite;
    sf::Texture texture;

    float moveSpeed;

    float ataqueTiempo;
    float ataqueTiempoMax;

    void iniciarVariables();

    
public:
    Jugador1();
    ~Jugador1();

    //*Accesorio
    const sf::Vector2f& getPos() const;
    const sf::FloatRect getLimites() const;

    void move(const float dirX, const float dirY);
    const bool puedesAtacar();

    void updateAtaque();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

void Jugador1::iniciarVariables(){
    this->moveSpeed = 6.f;

    this->ataqueTiempoMax = 10.f;
    this->ataqueTiempo = this->ataqueTiempoMax;
}


Jugador1::Jugador1(/* args */)
{
    this->iniciarVariables();
    this->texture.loadFromFile("Sprites\\Nave1.png");
    this->sprite.setTexture(this->texture);
    this->sprite.scale(0.8f, 0.8f);
    this->sprite.setPosition(sf::Vector2f(450 - sprite.getGlobalBounds().width,600 - sprite.getGlobalBounds().height ));
}

Jugador1::~Jugador1()
{
}

const sf::Vector2f& Jugador1::getPos() const{
    return this->sprite.getPosition();
}

const sf::FloatRect Jugador1::getLimites() const{
    return this->sprite.getGlobalBounds();
}

void Jugador1::move(const float dirX, const float dirY){
    this->sprite.move(this->moveSpeed * dirX, this->moveSpeed * dirY);
}

const bool Jugador1::puedesAtacar(){
    if(this->ataqueTiempo >= this->ataqueTiempoMax){
        this->ataqueTiempo = 0.f;
        return true;
    }
    return false;
}

void Jugador1::updateAtaque(){

    if(this->ataqueTiempo < this->ataqueTiempoMax)
        this->ataqueTiempo += 0.5f;
}

void Jugador1::update(){
    this->updateAtaque();
}

void Jugador1::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(this->sprite,states);   
}

#endif 