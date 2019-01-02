/*G³ówne okno w postaci singletonu
zawiera okno gry przez co powinno w przysz³oœci ³atwiej dodawaæ nowe
elementy
*/
#pragma once
#include "Biblioteki.h"

class MainWindow{
private:
	/*adres do singletonu*/
	static MainWindow* instance;
	/*prywatny konstruktor domyœlny do zapobiegania powstawaniu nowych instancji*/
	MainWindow();

	//obiekty g³ównego okna

	RenderWindow *window;
public:
	/*Dostêp do instancji okna*/
	static MainWindow* getMainWindow();

	/*Dostêp do g³ównego okna*/
	RenderWindow* getWindow();
	~MainWindow();
};
