#pragma once

#ifndef WINDOW_H
#define WINDOW_H


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class Window
{

public:
	//Anchura
	int anchura = 800;
	//Altura
	int altura = 600;
	Window();
	~Window();
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void run() = 0;


};

#endif // WINDOW_H
