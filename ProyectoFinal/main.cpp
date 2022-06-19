#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Header\\Personaje.h"
#include "Header\\Mascarilla.h"
#include "Header\\Boss1.h"
#include "Header\\Minion1.h"


int main()
{
    //!Inicializacion de la ventana
    sf::RenderWindow window(sf::VideoMode(800,600), "Invasion Covid");
    window.setFramerateLimit(60); //* 60 fps

    //*Personaje
    Personaje nave;
    Mascarilla masc;
    Boss1 b1;
    Minion1 m1, m2, m3, m4, m5, m6, m7, m8;

    m1.origen(125, 150);
    m2.origen(300, 150);
    m3.origen(475, 150);
    m4.origen(650, 150);
    m5.origen(125, 250);
    m6.origen(300, 250);
    m7.origen(475, 250);
    m8.origen(650, 250);

    //* Escenario

    sf::Sprite escenario;
    sf::Texture esc_texture;
    esc_texture.loadFromFile("Sprites/Escenario.jpg");
    escenario.setTexture(esc_texture);

    //* Audio
    sf::SoundBuffer buffer;
    buffer.loadFromFile("Audio\\theme.wav");

    sf::Sound sound;
    sound.setBuffer(buffer);
    //*sound.play();

    //!Game Loop
    while (window.isOpen()){

        //*Read Input - Actualizar estados de perifericos de entrada
        //*Leer la cola de mensajes
        sf::Event evnt;
        while (window.pollEvent(evnt)){
            if(evnt.type == sf::Event::Closed)
                window.close();
        }

        //*CMD - Comandos Joy

        //* Update - Actualiza los estados del juego
        nave.update();
        masc.update();
        window.clear();
        
        //* Draw
        window.draw(escenario);
        window.draw(nave);
        window.draw(masc);
        window.draw(b1);
        window.draw(m1);
        window.draw(m2);
        window.draw(m3);
        window.draw(m4);
        window.draw(m5);
        window.draw(m6);
        window.draw(m7);
        window.draw(m8);


        //*DISPLAY O FLIP

        window.display();
    }

    return 0;
}