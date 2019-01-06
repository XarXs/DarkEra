/*G��wna p�tla gry*/
#pragma once
#include "Biblioteki.h"

class Game{
	friend class MainMenu;
private:
	RenderWindow * okno;
	Clock stoper;

	MainMenu* mainMenu;
	//g��wne metody p�tli

	void proccesEvents();
	void update();
	void render();
public:
	//uruchumienie g��wnej p�tli gry
	void run();

	//konstruktor i destruktor
	Game();
	~Game();
};