#pragma once
#include "Biblioteki.h"

class Options{
	friend class MainMenu;
private:
	RenderWindow* okno;
	string pom;
	Text text;
	void render();//rysowanie
public:
	void run();	//uruchumienie panelu opcji

	Options();
};