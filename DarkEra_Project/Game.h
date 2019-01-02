/*G³ówna pêtla gry*/
#pragma once
#include "Biblioteki.h"

class Game{
private:
	RenderWindow * okno;
	Clock stoper;
	//g³ówne metody pêtli

	void proccesEvents();
	void update();
	void render();
public:
	//uruchumienie g³ównej pêtli gry
	void run();

	//konstruktor i destruktor
	Game();
	~Game();
};