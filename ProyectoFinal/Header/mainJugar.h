#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class mainJugar
{
private:
    int MainJugarSelected;
    Font font;
    Text mainJugarText[2];
public:
    mainJugar(int, int);
    void draw(RenderWindow& window);
    void MoveArriba();
    void MoveAbajo();
    int MainJugarPressed(){
        return MainJugarSelected;
    }
    ~mainJugar();
};

mainJugar::mainJugar(int width,int height)
{
    if(!font.loadFromFile("Fuente/BabyMonsta.otf")){
        cout << "No ahi una fuente aqui";
    }
    int tamsize = 40;
    //*1 jugador
    mainJugarText[0].setFont(font);
    mainJugarText[0].setFillColor(Color::White);
    mainJugarText[0].setString("1  Jugador");
    mainJugarText[0].setCharacterSize(tamsize);
    mainJugarText[0].setPosition(330,270);
    //*2 jugadores
    mainJugarText[1].setFont(font);
    mainJugarText[1].setFillColor(Color::White);
    mainJugarText[1].setString("2  Jugadores");
    mainJugarText[1].setCharacterSize(tamsize);
    mainJugarText[1].setPosition(330,410);
    MainJugarSelected = -1;
}

mainJugar::~mainJugar()
{
}

void mainJugar::draw(RenderWindow& window){
    for (int i = 0; i < 2; ++i){
        window.draw(mainJugarText[i]);
    }
}

void mainJugar::MoveArriba(){
    if (MainJugarSelected - 1 >= 0){
        mainJugarText[MainJugarSelected].setFillColor(Color::White);
        MainJugarSelected--;
        if (MainJugarSelected == -1){
            MainJugarSelected = 1;
        }
        mainJugarText[MainJugarSelected].setFillColor(Color::Yellow);
    }
}

void mainJugar::MoveAbajo(){
    if (MainJugarSelected - 1 <= 2){
        mainJugarText[MainJugarSelected].setFillColor(Color::White);
        MainJugarSelected++;
        if (MainJugarSelected == 2){
            MainJugarSelected = 0;
        }
        mainJugarText[MainJugarSelected].setFillColor(Color::Yellow);
    }
}
