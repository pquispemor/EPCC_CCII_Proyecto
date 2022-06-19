#ifndef MASCARILLA_H
#define MASCARILLA_H

#include <SFML\Graphics.hpp>

class Mascarilla : public sf::Drawable
{
private:
    sf::Sprite masc;
    sf::Texture masc_text;
    sf::Vector2f velMasc;
public:
    Mascarilla();
    ~Mascarilla();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

Mascarilla::Mascarilla()
{
    velMasc = {6,6};
    masc_text.loadFromFile("Sprites\\Mascarilla.png");
    masc.setTexture(masc_text);
}


Mascarilla::~Mascarilla()
{
}

void Mascarilla::update(){

    masc.move(velMasc);

    if(masc.getPosition().x < 0 ){
        velMasc.x = -velMasc.x;
    }
    if(masc.getPosition().y < 0){
        velMasc.y = -velMasc.y;
    }

    if(masc.getPosition().x + masc.getGlobalBounds().width > 800){
        velMasc.x = -velMasc.x;
    }

    if(masc.getPosition().y + masc.getGlobalBounds().height > 600){
        velMasc.y = -velMasc.y;
    }
}


void Mascarilla::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(masc, states);
}

#endif