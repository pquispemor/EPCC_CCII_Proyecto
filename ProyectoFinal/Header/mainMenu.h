#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class MainMenu
{
private:
    int MainMenuSelected;
    Font font;
    Text mainMenu[4];

public:
    MainMenu(int,int);
    void draw(RenderWindow& window);
    void MoveArriba();
    void MoveAbajo();
    int MainMenuPressed(){
        return MainMenuSelected;
    }
    ~MainMenu();
};

MainMenu::MainMenu(int width,int height)
{
    if(!font.loadFromFile("Fuente/BabyMonsta.otf")){
        cout << "No ahi una fuente aqui";
    }
    int tamsize = 50;
    //*Jugar
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color::White);
    mainMenu[0].setString("Jugar");
    mainMenu[0].setCharacterSize(tamsize);
    mainMenu[0].setPosition(340,250);
    //*Controles
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(Color::White);
    mainMenu[1].setString("Controles");
    mainMenu[1].setCharacterSize(tamsize);
    mainMenu[1].setPosition(300,320);
    //*Creditos;
    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(Color::White);
    mainMenu[2].setString("Creditos");
    mainMenu[2].setCharacterSize(tamsize);
    mainMenu[2].setPosition(320,390);
    //*Salir
    mainMenu[3].setFont(font);
    mainMenu[3].setFillColor(Color::White);
    mainMenu[3].setString("Salir");
    mainMenu[3].setCharacterSize(tamsize);
    mainMenu[3].setPosition(350,460);
    MainMenuSelected = -1;

}

MainMenu::~MainMenu()
{
}

void MainMenu::draw(RenderWindow& window){
    for (int i = 0; i < 4; ++i){
        window.draw(mainMenu[i]);
    }
}

void MainMenu::MoveArriba(){
    if (MainMenuSelected - 1 >= 0){
        mainMenu[MainMenuSelected].setFillColor(Color::White);
        MainMenuSelected--;
        if (MainMenuSelected == -1){
            MainMenuSelected = 2;
        }
        mainMenu[MainMenuSelected].setFillColor(Color::Blue);
    }
}

void MainMenu::MoveAbajo(){
    if (MainMenuSelected - 1 <= 4){
        mainMenu[MainMenuSelected].setFillColor(Color::White);
        MainMenuSelected++;
        if (MainMenuSelected == 4){
            MainMenuSelected = 0;
        }
        mainMenu[MainMenuSelected].setFillColor(Color::Blue);
    }
}

