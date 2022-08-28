#include "Multijugador.h"

auto ang = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine g1(ang);
std::uniform_int_distribution<> digits(0, 750);

/*La clase multijugador contiene métodos parecidos a los de clase UnJugador, solo se
diferencian al iniciar Jugadores.
Ya que este se encarga de iniciar a 2 jugadores.*/

void Multijugador::iniciarJugadores()
{
    this->jugador1 = new Jugador1();
    std::cout << *this->jugador1;
    this->jugador2 = new Jugador2();
    std::cout << *this->jugador2;
}

Multijugador::Multijugador()
{
    this->iniciarWindow();
    this->iniciarTextureBalas();
    this->iniciarGUI();
    this->iniciarJugadores();
    this->iniciarAudiosFijos();
    this->iniciarEnemigo();
    this->iniciarTextureFondo();
    this->iniciarAudioFase();
}

Multijugador::~Multijugador()
{
    delete this->window;
    delete this->jugador1;
    delete this->jugador2;

    //*Eliminar texturas
    for (auto& i : this->textures) {
        delete i.second;
    }

    //*Eliminar Balas
    for (auto* i : this->balas) {
        delete i;
    }

    //*Eliminar Minions1
    for (auto* i : this->enemigos) {
        delete i;
    }
}

void Multijugador::updateEntrada()
{
    /*También al método UpdateEntrada se le añaden las teclas del segundo jugador.*/
    //Jugador 1
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->jugador1->move(-1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->jugador1->move(1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->jugador1->move(0.f, -1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->jugador1->move(0.f, 1.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->jugador1->puedesAtacar()) {
        this->balas.push_back(new Bala(this->textures["BALAS"],
            this->jugador1->getPos().x + this->jugador1->getLimites().width / 2.f,
            this->jugador1->getPos().y, 0.f, -1.f, 5.f));
        sound_Disparo.play();
    }
    

    //Jugador 2
    /*Así como también en UpdateCombate se le agrega la colisión con el segundo jugador*/
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        this->jugador2->move(-1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        this->jugador2->move(1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        this->jugador2->move(0.f, -1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        this->jugador2->move(0.f, 1.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && this->jugador2->puedesAtacar()) {

        this->balas.push_back(new Bala(this->textures["BALAS"],
            this->jugador2->getPos().x + this->jugador2->getLimites().width / 2.f,
            this->jugador2->getPos().y, 0.f, -1.f, 5.f));
        sound_Disparo.play();
    }
}


void Multijugador::updateEnemigo()
{
    this->tiempoSpawn += 0.5f;
    if (this->tiempoSpawn >= this->tiempoSpawnMax)
    {
        this->enemigos.push_back(new Enemigo(digits(g1), 50.f));
        this->tiempoSpawn = 0.f;
    }
    if (unaVez == 1) {
        std::cout << *this->enemigos[0];
        unaVez = 0;
    }

    //*Update
    unsigned counter = 0;
    for (auto* minion1 : this->enemigos) {
        minion1->update();

        //Actualizacion de Enemigo por Niveles

        if (puntos > 500) {
            this->textureEnemigo.loadFromFile("Sprites\\Minion2.png");
            minion1->setTexture(textureEnemigo);
            minion1->setVelocidad(8.f);
        }
        if (puntos > 1000) {
            this->textureEnemigo.loadFromFile("Sprites\\Minion3.png");
            minion1->setTexture(textureEnemigo);
            minion1->setVelocidad(10.f);
        }
        if (puntos > 1500) {
            this->textureEnemigo.loadFromFile("Sprites\\Minion4.png");
            minion1->setTexture(textureEnemigo);
            minion1->setVelocidad(12.f);
        }
        if (puntos > 2000) {
            this->textureEnemigo.loadFromFile("Sprites\\Minion5.png");
            minion1->setTexture(textureEnemigo);
            minion1->setVelocidad(14.f);
        }

        //*Enemigos Colision con Pantalla
        if (minion1->getLimites().top > this->window->getSize().y) {
            //*Eliminar Enemigo
            delete this->enemigos.at(counter);
            this->enemigos.erase(this->enemigos.begin() + counter);
            --counter;

        }

        //*Colision enemigo - Jugador
        else if (minion1->getLimites().intersects(this->jugador1->getLimites())
            || minion1->getLimites().intersects(this->jugador2->getLimites())) {
            delete this->vidas.at(0);
            this->vidas.erase(this->vidas.begin() + 0);
            delete this->enemigos.at(counter);
            this->enemigos.erase(this->enemigos.begin() + counter);
            --counter;
            sound_impacto.play();
        }

        ++counter;
    }
    if (vidas.size() == 0) {
        derrota = true;
    }
}


void Multijugador::update()
{
    this->updatePollEvents();

    if (derrota == false and victoria == false) {
        this->updateEntrada();
        this->jugador1->update();
        this->jugador2->update();
        this->updateBalas();
        this->updateEnemigo();
    }

    this->updateEscenario();

    this->updateCombate();

    this->updatePuntuacion_Nivel();
}
/*Y por último se añade que se dibuje al segundo jugador.*/
void Multijugador::render()
{
    this->window->clear();
    this->window->draw(fondo);
    this->window->draw(*this->jugador1);
    this->window->draw(*this->jugador2);

    for (auto* bala : this->balas) {
        this->window->draw(*bala);
    }

    for (auto* vida : this->vidas) {
        this->window->draw(*vida);
    }

    for (auto* minion1 : this->enemigos) {
        this->window->draw(*minion1);
    }
    if (victoria == true) {
        this->window->draw(*this->resultV);
        sound_fase.stop();
    }
    if (derrota == true) {
        this->window->draw(*this->resultD);
        sound_fase.stop();
        if (ResultadoDUnaVez == 0) {
            (*resultD).sonido();
            ResultadoDUnaVez = 1;
        }
    }
    this->window->draw(puntuacionText);
    this->window->draw(nivelText);

    this->window->display();
}


