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
## INSTALACION SFML🔧
## PRUEBAS SFML🔩
**
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
**
[![288469022-2215510465270664-6466190466107157851-n.png](https://i.postimg.cc/g0pCBFrv/288469022-2215510465270664-6466190466107157851-n.png)](https://postimg.cc/pm0cpSfT)
## DISEÑO DE SPRITES🎨
## CAPTURAS📷
