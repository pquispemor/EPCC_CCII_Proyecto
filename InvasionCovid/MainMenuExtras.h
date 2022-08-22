#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
//Esta clse nos permite poner la opciones Jugar-Controles-Creditos-Salir
class MainMenuExtras : public sf::Drawable
{
private:
    //Guarda lo que se seleccionada
    int MainMenuSeleccion;
     //Fuente de tipo de letra
    sf::Font font;
    //Array de tamaño 4
    sf::Text mainMenu[4];
    //Iniciamos todas las variables
    void iniciarExtras();
public:
    //constructor y destructor
    MainMenuExtras();
    ~MainMenuExtras();
    //Metodo Mover Arriba
    void MoverArriba();
    //Metodo Mover Abajo
    void MoverAbajo();
    //Guarda la seleccion
    int MainMenuPressed();
    //recibe (ventana-estado) y es constante
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

