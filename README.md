# EPCC_CCII_Proyecto

﻿![NumCpp logo](https://github.com/pquispemor/EPCC_CCII_Proyecto/blob/main/ProyectoFinal/Fondos/IntroInforme.jpeg)
 
# Invasión Covid: Videojuego desarrollado en C++ Implementando la biblioteca SFML (https://www.sfml-dev.org/index.php)

## Autores✒️: 
* **Paul Jesus Quispe Morocco** pquispemor@unsa.edu.pe
* **Rodrigo Junior Santillana Quispe** rsantillanaq@unsa.edu.pe
* **Joaquín Ernesto Polar Espinoza** jpolare@unsa.edu.pe
* **Diego Alonso Zanabria Sacsi** dzanabria@unsa.edu.pe
* **Jhonathan Clavijo Chacaltana** jclavijoc@unsa.edu.pe
## Licencia 📄:
Este proyecto está bajo la Licencia (Tu Licencia) - mira el archivo [LICENSE.md](LICENSE.md) para detalles
## Realizado con 🛠️:
**C++ Standards:**  
[![C++14](https://img.shields.io/badge/C%2B%2B-14-blue.svg)](https://isocpp.org/std/the-standard)
[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://isocpp.org/std/the-standard)
[![C++20](https://img.shields.io/badge/C%2B%2B-20-blue.svg)](https://isocpp.org/std/the-standard)

**Compilers:**  
Visual Studio: 2017, 2019, 2022  
GNU: 7.3, 10.1  
SFML: 2.5.1

## INTRODUCCION🚀
## OBJETIVOS📋
* **OBJETIVOS GENERALES:** Desarrollar un videojuego 2D utilizando todos los temas avanzados en el curso. El juego estará basado en Galaga videojuego matamarcianos creado en 1981. Invasión COVID tratará sobre una nave la cual peleará contra oleadas de enemigos (virus Covid) con la finalidad de salvar al mundo de este virus. También existe un potenciador que es una mascarilla la cual tiene la finalidad de crear un escudo, el cual protege al jugador durante un pequeño lapso de tiempo y también otros ítems extras.
* **OBJETIVOS ESPECÍFICOS:** 
 - Se utilizará la biblioteca multimedia SFML.
* - Crear el arte de algunos personajes usando un software y exportandolo al proyecto.
* - Se crearán las clases: Jugadores, Enemigos, Colisiones, Balas, Score, Scenario, etc.
* - Se creará la opción multijugador la cual permitirá la presencia de 2 jugadores en el escenario.
## INSTALACION SFML🔧
## PRUEBAS SFML🔩
```C++
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
```
[![288469022-2215510465270664-6466190466107157851-n.png](https://i.postimg.cc/g0pCBFrv/288469022-2215510465270664-6466190466107157851-n.png)](https://postimg.cc/pm0cpSfT)
## DISEÑO DE SPRITES🎨
## CAPTURAS📷
