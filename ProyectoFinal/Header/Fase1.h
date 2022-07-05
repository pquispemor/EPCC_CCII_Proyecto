#ifndef FASE1_H
#define FASE1_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include "Jugador1.h"
#include "Bala.h"
#include "Minion1.h"
#include "Vida.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Fase1
{
private:

    //*Ventana
    sf::RenderWindow* window;
    sf::Sprite sprite;
    sf::Texture texture;
    
    sf::SoundBuffer fase1;
    sf::Sound sound_fase1;
    sf::SoundBuffer Atras;
    sf::Sound sound_Atras;
    sf::SoundBuffer Disparo;
    sf::Sound sound_Disparo;
    sf::SoundBuffer m1Dead;
    sf::Sound sound_m1Dead;
    sf::SoundBuffer winner;
    sf::Sound sound_win;
    sf::SoundBuffer loser;
    sf::Sound sound_loser;
    sf::SoundBuffer impacto;
    sf::Sound sound_impacto;


    //*Recursos
    map<std::string, sf::Texture*> textures;
    vector<Bala*> balas;

    //*Puntos System
    sf::Font font;
    sf::Text Fase1Text[2];

    //*Resultado Text
    sf::Font fontResultado;
    sf::Text DerrotaText;
    sf::Text VictoriaText;

    //*Vidas
    int cantVidas = 3;
    vector<Vida*> vidas;
    bool derrota = false;
    bool victoria = false;

    //* Puntuacion

    unsigned puntos;
    //*Jugador1
    Jugador1* jugador1;
    

    //*Enemigos
    float tiempoSpawn;
    float tiempoSpawnMax;
    vector<Minion1*> minions1;
    
    void iniciarWindow();
    void iniciarTexture();
    void iniciarSprite();

    void iniciarVida();
    void iniciarPuntuacion();
    void iniciarJugador1();
    void iniciarMinion1();
    void iniciarResultado();

public:
    Fase1(/* args */);
    ~Fase1();
    void run();

    void updatePollEvents();
    void updateEntrada();
    void updateCollision();
    void updatePuntuacion();
    void updateBalas();
    void updateMinion1();
    void updateCombate();
    void update();
    void render();
    void renderPuntuacion();
};

void Fase1::iniciarWindow(){
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Fase1");
    this->window->setFramerateLimit(60);
}

void Fase1::iniciarTexture(){
    this->texture.loadFromFile("Fondos\\Fase1.png");
    sprite.setTexture(this->texture);
    this->textures["BALAS"] = new sf::Texture();
    this->textures["BALAS"]->loadFromFile("Sprites\\DisparoPlayer1.png");
}


void Fase1::iniciarPuntuacion(){
    //Cargar Fuente de Letra
    this->puntos = 0;
    if(!this->font.loadFromFile("Fuente/BabyMonsta.otf")){
        cout << "No ahi una fuente aqui";
    }
    //*Nivel
    Fase1Text[0].setFont(this->font);
    Fase1Text[0].setCharacterSize(30);
    Fase1Text[0].setFillColor(sf::Color::White);
    Fase1Text[0].setString("1");
    Fase1Text[0].setPosition(440,8);

    //*Puntuacion
    Fase1Text[1].setFont(this->font);
    Fase1Text[1].setCharacterSize(30);
    Fase1Text[1].setFillColor(sf::Color::White);
    Fase1Text[1].setString("0");
    Fase1Text[1].setPosition(200,8);


}

void Fase1::iniciarResultado(){
    if(!this->fontResultado.loadFromFile("Fuente/BabyMonsta.otf")){
        cout << "No ahi una fuente aqui";
    }
    DerrotaText.setFont(this->fontResultado);
    DerrotaText.setCharacterSize(100);
    DerrotaText.setFillColor(sf::Color::White);
    DerrotaText.setString("Derrota");
    DerrotaText.setPosition(this->window->getSize().x/2 - 150,this->window->getSize().y/2 - 100);

    VictoriaText.setFont(this->fontResultado);
    VictoriaText.setCharacterSize(100);
    VictoriaText.setFillColor(sf::Color::White);
    VictoriaText.setString("Victoria");
    VictoriaText.setPosition(this->window->getSize().x/2 - 150,this->window->getSize().y/2 - 100);
}


void Fase1::iniciarJugador1(){
    this->jugador1 = new Jugador1();
}

void Fase1::iniciarVida(){
    int d = 650;
    for(int i=0;i<3;i++){
        this->vidas.push_back(new Vida(d,10));
        d+=50;
    }
}
void Fase1::iniciarMinion1(){
    this->tiempoSpawnMax = 20.f;
    this->tiempoSpawn = this->tiempoSpawnMax;
}

Fase1::Fase1(/* args */)
{
    this->iniciarWindow();
    this->iniciarTexture();
    fase1.loadFromFile("Audio\\Fase1-Batalla2.ogg");
    sound_fase1.setBuffer(fase1);
    sound_fase1.setVolume(50);
    Atras.loadFromFile("Audio\\Atras.ogg");
    sound_Atras.setBuffer(Atras);
    Disparo.loadFromFile("Audio\\Disparo.ogg");
    sound_Disparo.setBuffer(Disparo);
    m1Dead.loadFromFile("Audio\\minionDead.ogg");
    sound_m1Dead.setBuffer(m1Dead);
    winner.loadFromFile("Audio\\Winner.ogg");
    sound_win.setBuffer(winner);
    loser.loadFromFile("Audio\\Loser.ogg");
    sound_loser.setBuffer(loser);
    impacto.loadFromFile("Audio\\ImpactoNave.ogg");
    sound_impacto.setBuffer(impacto);
    this->iniciarPuntuacion();
    this->iniciarResultado();
    this->iniciarJugador1();
    this->iniciarVida();
    this->iniciarMinion1();
    sound_fase1.play();
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

void Fase1::updatePuntuacion() {
    std::stringstream ss;

    ss << this->puntos;

    this->Fase1Text[1].setString(ss.str());

    if (puntos >= 500){
        victoria = true;
    }

    //*Vidas

}

void Fase1::updateCollision(){

    //*Colision Izquierda
    if(this->jugador1->getLimites().left < 0.f){
        this->jugador1->setPosition(0.f, this->jugador1->getLimites().top);
    }
     //*Colision Derecha
    else if(this->jugador1->getLimites().left + this->jugador1->getLimites().width >= this->window->getSize().x){
        this->jugador1->setPosition(this->window->getSize().x - this->jugador1->getLimites().width, this->jugador1->getLimites().top);
    }
    //*Colision Arriba
    if(this->jugador1->getLimites().top < 0.f){
        this->jugador1->setPosition(this->jugador1->getLimites().left, 0.f);
    }
    
    //*Colision Abajo
    else if(this->jugador1->getLimites().top + this->jugador1->getLimites().height >= this->window->getSize().y){
        this->jugador1->setPosition(this->jugador1->getLimites().left, this->window->getSize().y - this->jugador1->getLimites().height);
    }
}


void Fase1::updateBalas(){

    unsigned counter = 0;
    for (auto *bala : this->balas){
        bala->update();

        //* Eliminación de balas (parte superior de la pantalla)
        if(bala->getLimites().top + bala->getLimites().height < 100.f){
            //*Eliminar Bala
            delete this->balas.at(counter);
            this->balas.erase(this->balas.begin() + counter);
            --counter;

        }

        ++counter;
    }
}

void Fase1::updateMinion1(){
    this->tiempoSpawn += 0.5f;
    if(this->tiempoSpawn >= this->tiempoSpawnMax)
    {
        this->minions1.push_back(new Minion1(rand() % this->window->getSize().x - 20.f, 50.f));
        this->tiempoSpawn = 0.f;
    }

    //*Update
    unsigned counter = 0;
    for (auto *minion1 : this->minions1){
        minion1->update();

        //*Enemigos Colision con Pantalla
        if(minion1->getLimites().top > this->window->getSize().y){
            //*Eliminar Enemigo
            delete this->minions1.at(counter);
            this->minions1.erase(this->minions1.begin() + counter);
            --counter;

        }

        //*Colision enemigo - Jugador
        else if(minion1->getLimites().intersects(this->jugador1->getLimites())){
            delete this->vidas.at(0);
            this->vidas.erase(this->vidas.begin() + 0);
            delete this->minions1.at(counter);
            this->minions1.erase(this->minions1.begin() + counter);
            --counter;
            sound_impacto.play();
        }

        ++counter;
    }
    if (vidas.size() == 0) {
        sound_loser.play();
        derrota = true;
    }
    
}

void Fase1::updateCombate(){
    for (int i = 0; i < this->minions1.size(); i++){

        bool minion1_delete = false;
        for (size_t k{0}; k < this->balas.size() && minion1_delete == false; k++){
            if (this->minions1[i]->getLimites().intersects(this->balas[k]->getLimites())){

                this->puntos += this->minions1[i]->getPuntos();
                
                delete this->minions1[i];
                this->minions1.erase(this->minions1.begin() + i);

                delete this->balas[k];
                this->balas.erase(this->balas.begin() + k);


                minion1_delete = true;
                sound_m1Dead.play();
            }
        }

    }
}

void Fase1::update(){
    this->updatePollEvents();

    this->updateEntrada();

    this->jugador1->update();

    this->updateCollision();

    this->updateBalas();

    if (derrota == false and victoria == false){
        this->updateMinion1();
    }
    this->updateCombate();

    this->updatePuntuacion();
}

void Fase1::renderPuntuacion(){
    for (int i = 0; i < 2; ++i){
        this->window->draw(Fase1Text[i]);
    }
}

void Fase1::render(){
    this->window->clear();
    this->window->draw(sprite);
    this->window->draw(*this->jugador1);

    for (auto *bala : this->balas){
        this->window->draw(*bala);
    }

    for (auto *vida : this->vidas){
        this->window->draw(*vida);
    }

    for (auto *minion1 : this->minions1){
        this->window->draw(*minion1);
    }
    if (victoria == true){
        this->window->draw(VictoriaText);
        sound_fase1.stop();
    }
    if (derrota == true){
        this->window->draw(DerrotaText);
        sound_fase1.stop();
    }
    this->renderPuntuacion();

    this->window->display();

}
#endif