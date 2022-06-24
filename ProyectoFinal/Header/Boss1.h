#ifndef BOSS1_H
#define BOSS1_H

#include <SFML\Graphics.hpp>

class Boss1 : public sf::Drawable
{
private:
    sf::Sprite boss1;
    sf::Texture boss1_text;
public:
    Boss1();
    ~Boss1();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

Boss1::Boss1()
{
    boss1_text.loadFromFile("Sprites\\BossFinal.png");
    boss1.setTexture(boss1_text);
    boss1.setOrigin(boss1.getGlobalBounds().width/2 - 400, boss1.getGlobalBounds().height/2 - 50);
}

Boss1::~Boss1()
{
}


void Boss1::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(boss1, states);
}

#endif