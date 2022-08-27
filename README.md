# EPCC_CCII_Proyecto

[![fondo.jpg](https://i.postimg.cc/P5mvJ41J/fondo.jpg)](https://postimg.cc/5X22k87W)
 
# Invasión Covid: Videojuego desarrollado en C++ Implementando la biblioteca SFML (https://www.sfml-dev.org/index.php)

## Autores✒️: 
* **Paul Jesus Quispe Morocco** pquispemor@unsa.edu.pe
* **Diego Alonso Zanabria Sacsi** dzanabria@unsa.edu.pe
* **Joaquin Ernesto Polar Espinoza** jpolare@unsa.edu.pe

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
* **OBJETIVOS ALCANZADOS:** Se pudo desarrollar con éxito el Juego 2D utilizando gran parte de los temas enseñados en el curso, aunque hubiera sido ideal abordarlos todos en mayor o menor medida, también aplicando la modalidad multijugador que nos permite jugar de manera local junto con otro usuario, se espera que la posible publicación futura del juego, cumpla el objetivo de incentivar a los jóvenes y niños sobre la vacunación contra el COVID-19.
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
## INSTALACION VISUAL STUDIO 2022
  + Ingresar a la pagina de descarga: https://visualstudio.microsoft.com/es/downloads/. Y elegir la opcion de Comunidad![image](https://user-images.githubusercontent.com/66225178/187043588-b6420657-7742-4848-9714-348e4a75c096.png)

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
  + Enlace de descarga: https://visualstudio.microsoft.com/es/vs/community/
  + Una vez instalado, asegurarse haber instalado “Desarrollo para el escritorio con C++”
  
    [![671f757d-b80b-4ddb-82e0-ebebbd3140f5.jpg](https://i.postimg.cc/WznN1MMZ/671f757d-b80b-4ddb-82e0-ebebbd3140f5.jpg)](https://postimg.cc/648JH4b6)

    [![b0119efc-e368-4802-805d-7778c310b632.jpg](https://i.postimg.cc/MZr3hck3/b0119efc-e368-4802-805d-7778c310b632.jpg)](https://postimg.cc/yWcTR880)

* ***DESCARGAR PROYECTO***
  + Ingresamos al enlace: https://github.com/pquispemor/EPCC_CCII_Proyecto
  + Descargamos el proyecto:
  
    [![d36efc39-8492-47f1-b1b8-e6261318ffc0.jpg](https://i.postimg.cc/SxQrRkpY/d36efc39-8492-47f1-b1b8-e6261318ffc0.jpg)](https://postimg.cc/gn5RB9jG)
    
  + Una vez descargado

    [![d0a73490-9a2e-46a7-9c03-a3bbe91d1f9c.jpg](https://i.postimg.cc/rFMGZMsZ/d0a73490-9a2e-46a7-9c03-a3bbe91d1f9c.jpg)](https://postimg.cc/fkq0J4xY)
    
  + Descomprimir 

    [![7f842711-a5d8-4884-b957-3a459106e745.jpg](https://i.postimg.cc/mk2DMXZj/7f842711-a5d8-4884-b957-3a459106e745.jpg)](https://postimg.cc/zb68YkgH)
    
    [![17320cc4-ac41-434d-ae34-0bd3651f7f86.jpg](https://i.postimg.cc/C1JMFGCq/17320cc4-ac41-434d-ae34-0bd3651f7f86.jpg)](https://postimg.cc/Q99ZmWy8)
 
 * ***EJECUTAR PROYECTO***
   + Abrimos VISUAL STUDIO
   + Una vez abierto le damos en 
   
     [![6213ae93-8ec9-4dcc-8379-5d819fbe640f.jpg](https://i.postimg.cc/jjsGRGMM/6213ae93-8ec9-4dcc-8379-5d819fbe640f.jpg)](https://postimg.cc/bZB6TFcn)
     
   + Buscamos la ruta del archivo que anteriormente descomprimido 
   
     [![613ecaec-46b2-4733-8e5d-2cd4183ec1b2.jpg](https://i.postimg.cc/fyhPgpS7/613ecaec-46b2-4733-8e5d-2cd4183ec1b2.jpg)](https://postimg.cc/mz8VPdwh)
     
   + Entramos en el archivo
   
     [![1bb46b0c-371c-4be0-818b-b1bfec3d47d2.jpg](https://i.postimg.cc/6qwHhZFY/1bb46b0c-371c-4be0-818b-b1bfec3d47d2.jpg)](https://postimg.cc/8JKBp7p6)
     
   + Le damos a InvasionCovid
   
     [![784970bd-bb83-4b38-906a-04c0dc8b00d9.jpg](https://i.postimg.cc/JztpKMdV/784970bd-bb83-4b38-906a-04c0dc8b00d9.jpg)](https://postimg.cc/87QdzQSt)
     
   + Le damos al archivo de nombre “InvasionCovid.sln” y empezara a abrir el proyecto
   
     [![1d0b13ec-be4f-46b6-a05a-0482b65cc07d.jpg](https://i.postimg.cc/d1R6D1Dd/1d0b13ec-be4f-46b6-a05a-0482b65cc07d.jpg)](https://postimg.cc/phTz6PfX)
     
   + Le damos en 
   
     [![010502b1-80e8-4ed7-a820-a00cd1351b16.jpg](https://i.postimg.cc/prXfTJwb/010502b1-80e8-4ed7-a820-a00cd1351b16.jpg)](https://postimg.cc/1n2n7wRJ)
     
   + Y finalmente se ejecutara el proyecto
   
     [![0463c7e7-0ae4-4b52-bd6d-8bfd420f319d.jpg](https://i.postimg.cc/sfNQ7zSZ/0463c7e7-0ae4-4b52-bd6d-8bfd420f319d.jpg)](https://postimg.cc/F10HX2T9)
     
   + PDT: Estos son los controles principales del proyecto para moverse en el menú (W,A,S,D) y para ingresar (Espacio).
   
     [![2efc56f8-e44b-4b13-b676-ff164cfb5a72.jpg](https://i.postimg.cc/4y9JpDkz/2efc56f8-e44b-4b13-b676-ff164cfb5a72.jpg)](https://postimg.cc/LgmKp0sX)
     

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
## Clases
  + Menu
  + MenuFactory
  + Menu Jugar
  + Menu Controles
  + Menu Creditos
  + Un jugador
  + Multijugador
  + Main
  + MainMenu
  + MainMenuExtras
  + Juego Principal
  + Jugador 2
  + Jugador Main
  + Jugador 1
  + Vida
  + Enemigo
  + Derrota
  + Bala
  + Victoria
## DIAGRAMA CODIGO
<img src="Informacion/Diagrama Estructura.png">

* **Fin**
