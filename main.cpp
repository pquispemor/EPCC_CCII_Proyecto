
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
int main(){
    RenderWindow window(VideoMode(512,512),"Invasion Covid alfa",Style::Close | Style::Resize);

    RectangleShape jugador(Vector2f(100.0f,100.0f));
    jugador.setPosition(206.0f,206.0f);
    Texture text_jugador;
    text_jugador.loadFromFile("player.png");
    jugador.setTexture(&text_jugador);
    while(window.isOpen()){
        Event evnt;
        while(window.pollEvent(evnt)){
            switch (evnt.type)
            {
            case Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }
        if(Keyboard::isKeyPressed(Keyboard::A)){
            jugador.move(-0.1f,0.0f);
        }
        if(Keyboard::isKeyPressed(Keyboard::D)){
            jugador.move(0.1f,0.0f);
        }
        if(Keyboard::isKeyPressed(Keyboard::W)){
            jugador.move(0.0f,-0.1f);
        }
        if(Keyboard::isKeyPressed(Keyboard::S)){
            jugador.move(0.0f,0.1f);
        }
        window.clear(Color(0, 0, 200));
        window.draw(jugador);
        window.display();
    }
    return 0;
}