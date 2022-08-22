#pragma once
#ifndef MULTIJUGADOR_H
#define MULTIJUGADOR_H

//SFML
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

//Random
#include <random>
#include <chrono>

//Clases
#include "JuegoPrincipal.h"
#include "Jugador1.h"
#include "Jugador2.h"

class Multijugador : public JuegoPrincipal
{

    void iniciarJugadores();

public:

    Multijugador();
    ~Multijugador();

    void updateEntrada();
    void updateEnemigo();
    void update();
    void render();
};


#endif
