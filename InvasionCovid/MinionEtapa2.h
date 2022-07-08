#pragma once
#ifndef MINIONETAPA2_H
#define MINIONETAPA2_H

#include <SFML\Graphics.hpp>

class MinionEtapa2 : public sf::Drawable
{
private:
    unsigned conteoPuntos;
    sf::Sprite sprite;
    sf::Texture texture;
    int tipo;
    float velocidad;
    int hp;
    int hpMax;
    int danio;
    int puntos;

    void iniciarVariables();
    void iniciarForma();

public:
    MinionEtapa2(float pos_x, float pos_y);
    ~MinionEtapa2();

    //*Accesorio
    const sf::FloatRect getLimites() const;
    const int& getPuntos() const;

    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif