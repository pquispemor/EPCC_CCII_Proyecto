#include "MenuFactory.h"
/*Dentro de esta clase encontraremos un objeto de la clase Menu y un método
getMenu(opción), este método se encargada de crear y retornar los diferentes menus,
dependiendo de la opción que reciba.*/
Menu* MenuFactory::getMenu(int opcion)
{
	switch (opcion) {
	case 1:
		menu = new MenuJugar;
		break;
	case 2:
		menu = new MenuControles;
		break;
	case 3:
		menu = new MenuCreditos;
		break;
	}

	return menu;
}
