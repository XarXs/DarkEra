/*G³ówna pêtla gry*/
#pragma once
#include "Biblioteki.h"

class Game{
	friend class MainMenu;
	friend class Player;
private:
	RenderWindow * okno;

	MainMenu* mainMenu;
	Player *player;
	//główne metody pêtli

	void proccesEvents();
	void update();
	void render();
public:
	//uruchumienie głównej pętli gry
	void run();

	//konstruktor i destruktor
	Game();
	~Game();
};