#pragma once
#ifndef JUGADORPRINCIPAL_H
#define JUGADORPRINCIPAL_H

//SFML
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <string>
#include <sstream>
#include <iostream>

//Random
#include <random>
#include <chrono>
#include <map>
#include <vector>

//Clases
#include "Jugador1.h"
#include "Bala.h"
#include "Vida.h"
#include "Enemigo.h"

//Resultados
#include "Victoria.h"
#include "Derrota.h"


/*Esta clase es importante ya que esta clase se encarga de heredar a las clases
UnJugador y Multijugador. Esta clase cuenta con todas las variables necesarias para las
clases ya mencionadas, asi como también sus métodos.*/

class JuegoPrincipal
{
protected:
    //*Ventana
    sf::RenderWindow* window;
    int anchura = 800;
    int altura = 600;
    int fps = 60;

    //Fondo y Audio
    sf::Sprite fondo;
    sf::Texture texture;
    sf::SoundBuffer fase;
    sf::Sound sound_fase;

    //*Enemigos
    float tiempoSpawn;
    float tiempoSpawnMax;
    std::vector<Enemigo*> enemigos;
    int unaVez = 1;
    
    /*Aquí encontramos variables para la ventana, para los sprites, sonidos y un tiempo de
    aparición de enemigos así como también un vector que almacena objetos de la clase
    Enemigo.*/


    //Variables Actualizacion Enemigos
    int tipo1 = 1;
    sf::Texture textureEnemigo;

    //Actualizacion de Escenario
    int cambio1 = 0;
    int cambio2 = 0;
    int cambio3 = 0;
    int cambio4 = 0;


    //Audios Extras
    sf::SoundBuffer Atras;
    sf::Sound sound_Atras;
    sf::SoundBuffer Disparo;
    sf::Sound sound_Disparo;
    sf::SoundBuffer enemigoDead;
    sf::Sound sound_enemigoDead;
    sf::SoundBuffer impacto;
    sf::Sound sound_impacto;
    /*Tenemos una textura el cual se encarga de cargar las diferentes texturas de enemigos
    al pasar de nivel.
    También encontramos estas variables de cambio, estas sirven para que al momento de
    que se actualize un escenario (cambio de fondo) solo se ejecute una vez, ya que todo
    esto se encuentra dentro de un bucle que está en constante ejecución mientras la
    ventana este abierta y si no contamos con estas variables el fondo va estar cargándose
    una y otra vez.*/
    
    //*Balas
    std::map<std::string, sf::Texture*> textures;
    std::vector<Bala*> balas;

    // ---- GUI ---
    //*Puntuacion
    sf::Font font;
    sf::Text puntuacionText;
    unsigned puntos;
    unsigned nivel = 1;

    //Nivel
    sf::Text nivelText;

    //Vidas
    int cantVidas = 3;
    std::vector<Vida*> vidas;

    //*Resultado Text
    int ResultadoDUnaVez = 0;
    int ResultadoVUnaVez = 0;
    //Patron de Diseño Singleton
    Derrota* resultD = Derrota::get_derrota();
    Victoria* resultV = Victoria::get_victoria();
    bool derrota = false;
    bool victoria = false;
    //Audio
    sf::SoundBuffer loser;
    sf::Sound sound_loser;

    //*Jugadores
    JugadorMain* jugador1;
    JugadorMain* jugador2;

    void iniciarWindow();
    void iniciarEnemigo();
    virtual void iniciarJugadores() {};
    void iniciarTextureFondo();
    void iniciarTextureBalas();
    void iniciarGUI();
    void iniciarAudioFase();
    void iniciarAudiosFijos();

public:
    JuegoPrincipal(/* args */) {};
    ~JuegoPrincipal();

    virtual void updateEntrada() = 0;
    void updatePuntuacion_Nivel();
    void updateEscenario();
    void updateBalas();
    void updatePollEvents();
    virtual void updateEnemigo() = 0;
    void updateCombate();
    virtual void update() = 0;
    virtual void render() = 0;
    void run();
};

#endif
