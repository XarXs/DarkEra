#pragma once
#include"Biblioteki.h"

class Game{
	friend class BasePlayer;
private:
	BasePlayer *p;	//pionek gracza

	void Events();	// egzekwowania eventów
	void Update();	// aktualizacja akcji
	void Render();	// renderowanie obrazu
public:
	void run();	// uruchamianie gry; włączanie głównej pętli
	Game();
	~Game();
};