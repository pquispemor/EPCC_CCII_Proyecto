#include "UnJugador.h"

/*Dentro de esta clase encontraremos el método random*/
auto eng = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine gen(eng);
std::uniform_int_distribution<> rand_digits(0, 750);
/*La inicialización de los jugadores. Aquí se utiliza polimorfismo.*/
void UnJugador::iniciarJugadores()
{
    this->jugador1 = new Jugador1();
    std::cout << *this->jugador1;
}

UnJugador::UnJugador()
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
/*Encontramos un destructor que se encarga de eliminar la ventana, al jugador, las
texturas de las balas, las balas y a los enemigos.*/
UnJugador::~UnJugador()
{
    delete this->window;
    delete this->jugador1;

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
/*Tambien tenemos el método update entrada el cual registra las teclas de movimiento y
disparo del jugador. Este también se encarga de crear balas al presionarse la tecla
Espacio. Tambien cuenta con una variable el cual haces que el jugador no pueda disparar
seguido, sino que este tenga que esperar unos segundos.*/

void UnJugador::updateEntrada()
{
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
}


void UnJugador::updateEnemigo()
{
    this->tiempoSpawn += 0.5f;
    if (this->tiempoSpawn >= this->tiempoSpawnMax)
    {
        this->enemigos.push_back(new Enemigo(rand_digits(gen), 50.f));
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
        else if (minion1->getLimites().intersects(this->jugador1->getLimites())) {
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

/*Tambien encontramos el método update enemigo en donde tenemos el tiempo de
spawn cada cuanto tiempo aparecen los enemigos, y en que coordenada aparecen.
Tambien tenemos la actualización de enemigos que estos cambian de sprite y
aumentan su velocidad al pasar un nivel. Este también se encarga de eliminar a los
enemigos cuando choquen con la parte inferior de la pantalla, asi como también
eliminarlos cuando choquen con el jugador y disminuirle una vida.
Tenemos un método update general que se encarga de llamar a los otros métodos
update.*/
void UnJugador::update()
{
    this->updatePollEvents();

    if (derrota == false and victoria == false) {
        this->updateEntrada();
        this->jugador1->update();
        this->updateBalas();
        this->updateEnemigo();
    }

    this->updateEscenario();

    this->updateCombate();

    this->updatePuntuacion_Nivel();
}
/*Por ultimo encontramos el método render, el cual se encarga de dibujar a todas las
clases.*/
void UnJugador::render()
{
    this->window->clear();
    this->window->draw(fondo);
    this->window->draw(*this->jugador1);

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
            resultD->sonido();
            (*resultD)("DERROTA");
            ResultadoDUnaVez = 1;
        }
    }
    this->window->draw(puntuacionText);
    this->window->draw(nivelText);

    this->window->display();
}


