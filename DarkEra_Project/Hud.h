/*Klasa obsługująca interface gracza*/

#pragma once
#include "Biblioteki.h"

class HUD{
private:
	RenderWindow* okno;
public:
	void render();
	HUD();
};