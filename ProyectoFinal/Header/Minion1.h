#ifndef MINION1_H
#define MINION1_H

#include <SFML\Graphics.hpp>

class Minion1 : public sf::Drawable
{
private:
    int x,y;
    sf::Sprite sprite;
    sf::Texture sprite_text;
public:
    Minion1();
    ~Minion1();
    void origen(int,int);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

Minion1::Minion1()
{
    sprite_text.loadFromFile("Sprites\\Minion1.png");
    sprite.setTexture(sprite_text);
}

Minion1::~Minion1()
{
}

void Minion1::origen(int x, int y){
    sprite.setOrigin(sprite.getGlobalBounds().width/2 - x, sprite.getGlobalBounds().height/2 - y);
}

void Minion1::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(sprite, states);
}

#endif