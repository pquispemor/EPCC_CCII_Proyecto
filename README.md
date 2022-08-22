# EPCC_CCII_Proyecto

[![fondo.jpg](https://i.postimg.cc/P5mvJ41J/fondo.jpg)](https://postimg.cc/5X22k87W)
 
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
* En estos tiempos post-pandemia las personas buscan adaptarse para convivir con esta nueva normalidad. Nuestro proyecto consta de un videojuego que tiene como  objetivo poder llegar a la mayor parte de la poblacion que son los niños y jovenes, para recordarles la importancia de la vacuna del COVID-19.

## OBJETIVOS📋
* **OBJETIVOS GENERALES:** Desarrollar un videojuego 2D utilizando todos los temas avanzados en el curso. El juego estará basado en Galaga videojuego matamarcianos creado en 1981. Invasión COVID tratará sobre una nave la cual peleará contra oleadas de enemigos (virus Covid) con la finalidad de salvar al mundo de este virus. También existe un potenciador que es una mascarilla la cual tiene la finalidad de crear un escudo, el cual protege al jugador durante un pequeño lapso de tiempo y también otros ítems extras.
* **OBJETIVOS ESPECÍFICOS:** 
  + Se utilizará la biblioteca multimedia SFML.
  + Crear el arte de algunos personajes usando un software y exportandolo al proyecto.
  + Se crearán las clases: Jugadores, Enemigos, Colisiones, Balas, Score, Scenario, etc.
  + Se creará la opción multijugador la cual permitirá la presencia de 2 jugadores en el escenario.
  + Incentivar a los jóvenes y niños a ponerse la vacuna contra el COVID-19.
## INSTALACION SFML🔧
* LINK DE REFERENCIA: https://www.sfml-dev.org/tutorials/2.5/start-vc.php
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
## DISEÑO DE SPRITES🎨: 
* Para el diseño de Algunos Sprites como en este caso los menus se utlizo el editor de gráficos vectoriales Adobe Illustrator.

   + ***Adobe illustration Controles***
     [![Whats-App-Image-2022-06-24-at-11-51-49-PM.jpg](https://i.postimg.cc/zvrm4yzX/Whats-App-Image-2022-06-24-at-11-51-49-PM.jpg)](https://postimg.cc/HcBPys8f)
   + **Adobe Illustration Creditos**
     [![Whats-App-Image-2022-06-24-at-11-51-55-PM.jpg](https://i.postimg.cc/7PMjfYP0/Whats-App-Image-2022-06-24-at-11-51-55-PM.jpg)](https://postimg.cc/hhv2Yndt)
* **Y para dar los ultimos retoques se utilizo adobe Photoshop. Es una herramienta ampliamente reconocida por su uso en la creación y edición de imágenes como gráficos.**
[![Whats-App-Image-2022-06-24-at-11-51-59-PM.jpg](https://i.postimg.cc/N0HzYQPy/Whats-App-Image-2022-06-24-at-11-51-59-PM.jpg)](https://postimg.cc/R3vRLxm9)
   
## MANUAL DE INSTALACIÓN DEL PPROYECTO
* ***DESCARGAR VISUAL STUDIO(Si tienes VISUAL STUDIO saltar este paso)***

## CAPTURAS📷
* **Inicio o Menu**

[![Whats-App-Image-2022-06-25-at-2-08-51-AM.jpg](https://i.postimg.cc/285HY3r5/Whats-App-Image-2022-06-25-at-2-08-51-AM.jpg)](https://postimg.cc/qg9cXJtf)
* **Controles**

[![Whats-App-Image-2022-06-25-at-2-09-23-AM.jpg](https://i.postimg.cc/m207nrrJ/Whats-App-Image-2022-06-25-at-2-09-23-AM.jpg)](https://postimg.cc/PPQLpTYQ)
* **Creditos**

[![Whats-App-Image-2022-06-25-at-2-09-40-AM.jpg](https://i.postimg.cc/X7Fg45t4/Whats-App-Image-2022-06-25-at-2-09-40-AM.jpg)](https://postimg.cc/w7qNk16G)
* **Selección de jugador**

[![Whats-App-Image-2022-06-25-at-2-10-16-AM.jpg](https://i.postimg.cc/hj69q4rX/Whats-App-Image-2022-06-25-at-2-10-16-AM.jpg)](https://postimg.cc/gXywVW1p)
* **Juego en ejecución**


[![Whats-App-Image-2022-06-25-at-2-08-14-AM.jpg](https://i.postimg.cc/Df1Wzcfj/Whats-App-Image-2022-06-25-at-2-08-14-AM.jpg)](https://postimg.cc/s1Df67h7)

## DIAGRAMA CODIGO

<img src="Informacion/Diagrama Codigo - Invasion Covid.PNG">

* **Fin**
