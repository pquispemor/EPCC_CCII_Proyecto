#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML\Graphics.hpp>

class Personaje : public sf::Drawable
{
    sf::Sprite _sprite;
    sf::Texture _textura;
    float _velocidad;
public:
    Personaje();
    ~Personaje();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

Personaje::Personaje()
{
    _velocidad = 6;
    _textura.loadFromFile("Sprites\\Jeringa.png");
    _sprite.setTexture(_textura);
    _sprite.setPosition(sf::Vector2f(450 - _sprite.getGlobalBounds().width,600 - _sprite.getGlobalBounds().height ));
}

Personaje::~Personaje(){}



void Personaje::update(){

    //*CMD - Comandos Joy
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        _sprite.move(0,-_velocidad);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        _sprite.move(-_velocidad,0);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){            
        _sprite.move(0,_velocidad);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        _sprite.move(_velocidad,0);
    }

    //*Para no salir de la pantalla
    //* COORDENADA X
    if(_sprite.getPosition().x < 0 ){
        _sprite.setPosition(0, _sprite.getPosition().y);
    }
    if(_sprite.getPosition().x + _sprite.getGlobalBounds().width > 800){
        _sprite.setPosition(800 - _sprite.getGlobalBounds().width, _sprite.getPosition().y);
    }
    //* COORDENADA Y
    if(_sprite.getPosition().y < 0){
        _sprite.setPosition(_sprite.getPosition().x, 0);
    }
    if(_sprite.getPosition().y + _sprite.getGlobalBounds().height > 600){
        _sprite.setPosition(_sprite.getPosition().x, 600 - _sprite.getGlobalBounds().height);
    }
}


void Personaje::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(_sprite, states);
}

#endif