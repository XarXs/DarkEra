/*G��wne okno w postaci singletonu
zawiera okno gry przez co powinno w przysz�o�ci �atwiej dodawa� nowe
elementy
*/
#pragma once
#include "Biblioteki.h"

class MainWindow{
private:
	/*adres do singletonu*/
	static MainWindow* instance;
	/*prywatny konstruktor domy�lny do zapobiegania powstawaniu nowych instancji*/
	MainWindow();

	//obiekty g��wnego okna

	RenderWindow *window;
public:
	/*Dost�p do instancji okna*/
	static MainWindow* getMainWindow();

	/*Dost�p do g��wnego okna*/
	RenderWindow* getWindow();
	~MainWindow();
};
