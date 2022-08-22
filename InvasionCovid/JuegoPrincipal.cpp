#include "JuegoPrincipal.h"

void JuegoPrincipal::iniciarWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(anchura, altura), "Juego");
    this->window->setFramerateLimit(fps);
}

void JuegoPrincipal::iniciarEnemigo()
{
    this->tiempoSpawnMax = 20.f;
    this->tiempoSpawn = this->tiempoSpawnMax;
}

void JuegoPrincipal::iniciarTextureFondo()
{
    this->texture.loadFromFile("Fondos\\Fase1.png");
    fondo.setTexture(this->texture);
}

void JuegoPrincipal::iniciarTextureBalas()
{
    this->textures["BALAS"] = new sf::Texture();
    this->textures["BALAS"]->loadFromFile("Sprites\\DisparoPlayer1.png");
}

void JuegoPrincipal::iniciarGUI()
{
    //Cargar Fuente de Letra
    this->puntos = 0;
    if (!this->font.loadFromFile("Fuente/BabyMonsta.otf")) {
        std::cout << "No ahi una fuente aqui";
    }
    //Puntuacion
    puntuacionText.setFont(this->font);
    puntuacionText.setCharacterSize(30);
    puntuacionText.setFillColor(sf::Color::White);
    puntuacionText.setString("0");
    puntuacionText.setPosition(200, 8);

    //Vida
    float distanciaVida = 650;
    for (int i = 0; i < 3; i++) {
        this->vidas.push_back(new Vida(distanciaVida, 10));
        distanciaVida += 50;
    }
    //Nivel
    //Cargar Fuente de Letra
    if (!this->font.loadFromFile("Fuente/BabyMonsta.otf")) {
        std::cout << "No ahi una fuente aqui";
    }
    //*Nivel
    nivelText.setFont(this->font);
    nivelText.setCharacterSize(30);
    nivelText.setFillColor(sf::Color::White);
    nivelText.setString("1");
    nivelText.setPosition(440, 8);
}

void JuegoPrincipal::iniciarAudioFase()
{
    fase.loadFromFile("Audio\\Musica1.ogg");
    sound_fase.setBuffer(fase);
    sound_fase.setVolume(50);
    sound_fase.play();
}

void JuegoPrincipal::iniciarAudiosFijos()
{
    Atras.loadFromFile("Audio\\AudioMainMenu\\EscapePush.ogg");
    sound_Atras.setBuffer(Atras);
    Disparo.loadFromFile("Audio\\Disparo.ogg");
    sound_Disparo.setBuffer(Disparo);
    sound_Disparo.setVolume(50);
    enemigoDead.loadFromFile("Audio\\EnemigoDead2.ogg");
    sound_enemigoDead.setBuffer(enemigoDead);
    impacto.loadFromFile("Audio\\ImpactoNave.ogg");
    sound_impacto.setBuffer(impacto);
}


JuegoPrincipal::~JuegoPrincipal()
{

}

void JuegoPrincipal::updatePuntuacion_Nivel()
{
    std::stringstream ss;

    ss << this->puntos;

    this->puntuacionText.setString(ss.str());


    std::stringstream sn;
    sn << this->nivel;
    this->nivelText.setString(sn.str());
}

void JuegoPrincipal::updateEscenario()
{
    if (puntos >= 500) {
        if (cambio1 == 0) {
            this->texture.loadFromFile("Fondos\\Fase2.png");
            fondo.setTexture(this->texture);
            cambio1 = 1;
            nivel++;
        }
    }
    if (puntos >= 1000) {
        if (cambio2 == 0) {
            this->texture.loadFromFile("Fondos\\Fase3.png");
            fondo.setTexture(this->texture);
            cambio2 = 1;
            nivel++;
        }
    }

    if (puntos >= 1500) {
        if (cambio3 == 0) {
            this->texture.loadFromFile("Fondos\\Fase4.png");
            fondo.setTexture(this->texture);
            cambio3 = 1;
            nivel++;
        }
    }

    if (puntos >= 2000) {
        if (cambio4 == 0) {
            this->texture.loadFromFile("Fondos\\Fase5.png");
            fondo.setTexture(this->texture);
            cambio4 = 1;
            nivel++;
        }
    }

    if (puntos >= 2500) {
        victoria = true;
        if (ResultadoVUnaVez == 0) {
            resultV->sonido();
            (*resultV)("VICTORIA");
            ResultadoVUnaVez = 1;
        }
    }
}

void JuegoPrincipal::updateBalas()
{
    unsigned counter = 0;
    for (auto* bala : this->balas) {
        bala->update();

        //* Eliminación de balas (parte superior de la pantalla)
        if (bala->getLimites().top + bala->getLimites().height < 100.f) {
            //*Eliminar Bala
            delete this->balas.at(counter);
            this->balas.erase(this->balas.begin() + counter);
            --counter;

        }

        ++counter;
    }
}

void JuegoPrincipal::updatePollEvents()
{
    sf::Event e;
    while (this->window->pollEvent(e))
    {
        if (e.type == sf::Event::Closed) {
            sound_Atras.play();
            this->window->close();
        }
        if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape) {
            sound_Atras.play();
            this->window->close();
        }
    }
}

void JuegoPrincipal::updateCombate()
{
    for (int i = 0; i < this->enemigos.size(); i++) {

        bool minion1_delete = false;
        for (size_t k{ 0 }; k < this->balas.size() && minion1_delete == false; k++) {
            if (this->enemigos[i]->getLimites().intersects(this->balas[k]->getLimites())) {

                this->puntos += this->enemigos[i]->getPuntos();
                delete this->enemigos[i];
                this->enemigos.erase(this->enemigos.begin() + i);

                delete this->balas[k];
                this->balas.erase(this->balas.begin() + k);

                minion1_delete = true;
                sound_enemigoDead.play();
            }
        }
    }
}

void JuegoPrincipal::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}

