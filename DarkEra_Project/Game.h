/*G³ówna pêtla gry*/
#pragma once
#include "Biblioteki.h"

class Game{
	friend class MainMenu;
	friend class Mapa;
	friend class Player;
	friend class Token;
private:
	RenderWindow * okno;
	Mapa* map;
	MainMenu* mainMenu;
	//Player* player;
	Token* player;
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