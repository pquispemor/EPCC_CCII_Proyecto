#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include "Header\\Fase1.h"
#include "Header\\mainMenu.h"
#include "Header\\mainJugar.h"
#include "Header\\Boss1.h"
#include "Header\\Minion1.h"
#include "Header\\Bala.h"

using namespace std;
using namespace sf;

int main()
{

    srand(time(static_cast<unsigned>(0)));
    //!Inicializacion de la ventana
    sf::RenderWindow window(sf::VideoMode(800,600), "Invasion Covid");
    MainMenu mainMenu(window.getSize().x, window.getSize().y);
    mainJugar mJugar(window.getSize().x, window.getSize().y);
    window.setFramerateLimit(60); //* 60 fps
    
    //* Escenario Menu

    sf::Sprite menu;
    sf::Texture esc_texture;
    esc_texture.loadFromFile("Fondos/menu.png");
    menu.setTexture(esc_texture);

    //* Fondo Jugar

    sf::Sprite MenuJugar;
    sf::Texture MJugar_texture;
    MJugar_texture.loadFromFile("Fondos/SeleccionSinBotones.png");
    MenuJugar.setTexture(MJugar_texture);

    //* Fondo Controles

    sf::Sprite MenuControles;
    sf::Texture MControles_texture;
    MControles_texture.loadFromFile("Fondos/Controles.png");
    MenuControles.setTexture(MControles_texture);

    //* Fondo Creditos

    sf::Sprite MenuCreditos;
    sf::Texture MCreditos_texture;
    MCreditos_texture.loadFromFile("Fondos/Creditos.png");
    MenuCreditos.setTexture(MCreditos_texture);

    //*Audio Fase1

    sf::SoundBuffer fase1;
    sf::Sound sound_fase1;
    fase1.loadFromFile("Audio\\Fase1Theme.ogg");
    sound_fase1.setBuffer(fase1);
    sound_fase1.setVolume(50);

    //* Audio
    sf::SoundBuffer buffer;
    buffer.loadFromFile("Audio\\BombeIntro.ogg");

    sf::SoundBuffer move;
    move.loadFromFile("Audio\\PushInicio.ogg");

    sf::SoundBuffer push;
    push.loadFromFile("Audio\\SpacePush.ogg");


    sf::SoundBuffer Atras;
    Atras.loadFromFile("Audio\\Atras.ogg");

    //*-------------------------------------
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    sound.setLoop(true);

    sound.setVolume(50);

    sf::Sound sound_move;
    sound_move.setBuffer(move);
    sf::Sound sound_push;
    sound_push.setBuffer(push);
    sf::Sound sound_Atras;
    sound_Atras.setBuffer(Atras);

    //!Game Loop
    while (window.isOpen()){

        //*Read Input - Actualizar estados de perifericos de entrada
        //*Leer la cola de mensajes
        sf::Event event;
        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == Event::KeyPressed){
                if(event.key.code == Keyboard::Escape){
                    window.close();
                }
            }
            if(event.type == Event::KeyReleased){
                if(event.key.code == Keyboard::W){
                    mainMenu.MoveArriba();
                    sound_move.play();
                    break;
                }
                if(event.key.code == Keyboard::S){
                    mainMenu.MoveAbajo();
                    sound_move.play();
                    break;
                }
                if(event.key.code == Keyboard::Space){
                    sound_push.play();
                    int x = mainMenu.MainMenuPressed();
                    if (x == 0){
                        RenderWindow jugar(VideoMode(800, 600), "Invasion Covid");
                        while (jugar.isOpen()){
                            Event event_jugar;
                            while (jugar.pollEvent(event_jugar)){
                                if(event_jugar.type == Event::Closed){
                                    jugar.close();
                                }
                                if(event_jugar.type == Event::KeyPressed){
                                    if(event_jugar.key.code == Keyboard::Escape){
                                        jugar.close();
                                        sound_Atras.play();
                                    }
                                }
                                if(event_jugar.type == Event::KeyReleased){
                                    if(event_jugar.key.code == Keyboard::W){
                                        mJugar.MoveArriba();
                                        sound_move.play();
                                        break;
                                    }
                                    if(event_jugar.key.code == Keyboard::S){
                                        mJugar.MoveAbajo();
                                        sound_move.play();
                                        break;
                                    }

                                    if(event_jugar.key.code == Keyboard::Space){
                                        sound_push.play();
                                        sound.stop();
                                        int x = mJugar.MainJugarPressed();
                                        if (x == 0){
                                            Fase1 fase1_juego;
                                            sound_fase1.play();
                                            fase1_juego.run();
                                            sound_fase1.stop();
                                        }
                                        sound.play();                                 
                                        if (x == 1){
                                            RenderWindow multiJugador(VideoMode(800, 600), "Invasion Covid");
                                            multiJugador.setFramerateLimit(60); //* 60 fps
                                            while (multiJugador.isOpen()){
                                                Event evento;
                                                while (multiJugador.pollEvent(evento)){
                                                    if(evento.type == Event::Closed){
                                                        multiJugador.close();
                                                        sound_Atras.play();
                                                        sound.play();
                                                    }
                                                    if(evento.type == Event::KeyPressed){
                                                        if(evento.key.code == Keyboard::Escape){
                                                            multiJugador.close();
                                                            sound_Atras.play();
                                                            sound.play();
                                                        }
                                                    }
                                                }
                                                multiJugador.clear();
                                                multiJugador.display();
                                            }
                                        }
                                    
                                    }
                                }
                            }
                            jugar.clear();
                            jugar.draw(MenuJugar);
                            mJugar.draw(jugar);
                            jugar.display();
                        }
                    }
                    if (x == 1){
                        RenderWindow controles(VideoMode(800, 600), "Invasion Covid");
                        while (controles.isOpen()){
                            Event evento;
                            while (controles.pollEvent(evento)){
                                if(evento.type == Event::Closed){
                                    controles.close();
                                }
                                if(evento.type == Event::KeyPressed){
                                    if(evento.key.code == Keyboard::Escape){
                                        controles.close();
                                        sound_Atras.play();
                                    }
                                }
                            }
                            controles.clear();
                            controles.draw(MenuControles);
                            controles.display();
                        }
                    }

                    if (x == 2){  
                        RenderWindow creditos(VideoMode(800, 600), "Invasion Covid");
                        while (creditos.isOpen()){
                            Event event_creditos;
                            while (creditos.pollEvent(event_creditos)){
                                if(event_creditos.type == Event::Closed){
                                    creditos.close();
                                }
                                if(event_creditos.type == Event::KeyPressed){
                                    if(event_creditos.key.code == Keyboard::Escape){
                                        creditos.close();
                                        sound_Atras.play();
                                    }
                                }
                            }
                            creditos.clear();
                            creditos.draw(MenuCreditos);
                            creditos.display();
                        }
                    }

                    if (x == 3)
                        window.close();
                    break;    
                }
            }
        }

        //*CMD - Comandos Joy

        //* Update - Actualiza los estados del juego
        window.clear();
        
        //* Draw
        window.draw(menu);
        mainMenu.draw(window);

        //*DISPLAY O FLIP

        window.display();
    }

    return 0;
}