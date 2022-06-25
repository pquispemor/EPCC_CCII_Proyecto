#ifndef FASE1_H
#define FASE1_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include "Jugador1.h"
#include "Bala.h"
#include "Minion1.h"
#include <iostream>

using namespace std;

class Fase1
{
private:

    //*Ventana
    sf::RenderWindow* window;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::SoundBuffer Atras;
    sf::Sound sound_Atras;
    sf::SoundBuffer Disparo;
    sf::Sound sound_Disparo;
    sf::SoundBuffer m1;
    sf::Sound sound_m1;
    sf::SoundBuffer m1Dead;
    sf::Sound sound_m1Dead;
    //*Recursos
    map<std::string, sf::Texture*> textures;
    vector<Bala*> balas;

    //*Jugador1
    Jugador1* jugador1;

    //*Enemigos
    float tiempoSpawn;
    float tiempoSpawnMax;
    vector<Minion1*> minions1;
    
    void iniciarWindow();
    void iniciarTexture();
    void iniciarSprite();

    void iniciarJugador1();
    void iniciarMinion1();

public:
    Fase1(/* args */);
    ~Fase1();
    void run();

    void updatePollEvents();
    void updateEntrada();
    void updateBalas();
    void updateMinion1yCombate();
    void update();
    void render();
};

void Fase1::iniciarWindow(){
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Fase1");
    this->window->setFramerateLimit(60);
}

void Fase1::iniciarTexture(){
    this->textures["BALAS"] = new sf::Texture();
    this->textures["BALAS"]->loadFromFile("Sprites\\Jeringa.png");
}

void Fase1::iniciarJugador1(){
    this->jugador1 = new Jugador1();
}

void Fase1::iniciarMinion1(){
    this->tiempoSpawnMax = 20.f;
    this->tiempoSpawn = this->tiempoSpawnMax;
}

Fase1::Fase1(/* args */)
{
    this->iniciarWindow();
    this->iniciarTexture();
    this->texture.loadFromFile("Fondos\\Fase1.jpg");
    sprite.setTexture(this->texture);
    Atras.loadFromFile("Audio\\Atras.ogg");
    sound_Atras.setBuffer(Atras);
    Disparo.loadFromFile("Audio\\Disparo.ogg");
    sound_Disparo.setBuffer(Disparo);
    m1.loadFromFile("Audio\\minion1.ogg");
    sound_m1.setBuffer(m1);
    m1Dead.loadFromFile("Audio\\minionDead.ogg");
    sound_m1Dead.setBuffer(m1Dead);
    this->iniciarJugador1();
    this->iniciarMinion1();
}

Fase1::~Fase1()
{
    delete this->window;
    delete this->jugador1;

    //*Eliminar texturas
    for (auto &i : this->textures){
        delete i.second;
    }

    //*Eliminar Balas
    for (auto *i : this->balas){
        delete i;
    }

    //*Eliminar Minions1
    for (auto *i : this->minions1){
        delete i;
    }
}

void Fase1::run(){
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}

void Fase1::updatePollEvents(){
    sf::Event e;
    while (this->window->pollEvent(e))
    {
        if (e.type == sf::Event::Closed){
            sound_Atras.play();
            this->window->close();
        }
        if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape){
            sound_Atras.play();
            this->window->close();
        }
    }
}

void Fase1::updateEntrada(){
    //Jugador1 update
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->jugador1->move(-1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->jugador1->move(1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->jugador1->move(0.f, -1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->jugador1->move(0.f, 1.f);
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->jugador1->puedesAtacar()){
        this->balas.push_back(new Bala(this->textures["BALAS"],
         this->jugador1->getPos().x + this->jugador1->getLimites().width/2.f,
          this->jugador1->getPos().y, 0.f, -1.f, 5.f));
        sound_Disparo.play();
    }


}

void Fase1::updateBalas(){

    unsigned counter = 0;
    for (auto *bala : this->balas){
        bala->update();

        //* Eliminación de balas (parte superior de la pantalla)
        if(bala->getLimites().top + bala->getLimites().height < 0.f){
            //*Eliminar Bala
            delete this->balas.at(counter);
            this->balas.erase(this->balas.begin() + counter);
            --counter;

        }

        ++counter;
    }
}

void Fase1::updateMinion1yCombate(){
    this->tiempoSpawn += 0.5f;
    if(this->tiempoSpawn >= this->tiempoSpawnMax)
    {
        sound_m1.play();
        this->minions1.push_back(new Minion1(rand() % this->window->getSize().x - 20.f, -100.f));
        this->tiempoSpawn = 0.f;
    }

    for (int i = 0; i < this->minions1.size(); i++){
        bool minion1_removed = false;
        this->minions1[i]->update();

        for( size_t k = 0; k < this->balas.size() && !minion1_removed; k++){
            if (this->balas[k]->getLimites().intersects(this->minions1[i]->getLimites())){
                this->balas.erase(this->balas.begin() + k);
                this->minions1.erase(this->minions1.begin() + i);
                minion1_removed = true;
                sound_m1Dead.play();
            }
        }

        //*Eliminar enemigos cuando llegen abajo
        if (!minion1_removed){
            if (this->minions1[i]->getLimites().top > this->window->getSize().y){
                this->minions1.erase(this->minions1.begin() + i);
                minion1_removed = true;
            }
        }
    }
    
}

void Fase1::update(){
    this->updatePollEvents();

    this->updateEntrada();

    this->jugador1->update();

    this->updateBalas();

    this->updateMinion1yCombate();
}

void Fase1::render(){
    this->window->clear();
    this->window->draw(sprite);
    this->window->draw(*this->jugador1);

    for (auto *bala : this->balas){
        this->window->draw(*bala);
    }

    for (auto *minion1 : this->minions1){
        this->window->draw(*minion1);
    }

    this->window->display();

}
#endif