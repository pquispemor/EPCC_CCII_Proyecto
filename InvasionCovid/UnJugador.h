#pragma once
#ifndef UNJUGADOR_H
#define UNJUGADOR_H

//SFML
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

//Random
#include <random>
#include <chrono>

//Clases
#include "JuegoPrincipal.h"

class UnJugador : public JuegoPrincipal
{
private:

    void iniciarJugadores();

public:
    UnJugador(/* args */);
    ~UnJugador();

    void updateEntrada();
    void updateEnemigo();
    void update();
    void render();
};


#endif