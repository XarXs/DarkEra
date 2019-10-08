/*
Bazowa klasa postaci.
W podstawowej wersji zawiera metody odpowiedzialne za poruszanie się,
wyświetlanie wizerunku oraz będzie zawierać podstawowe statystyki.
*/

#pragma once
#include "Biblioteki.h"

class PlayerToken{
private:
	Vector2f position;			//aktualna pozycja gracza
	int speed;
	RenderWindow* okno;
	View view;
public:
	void render();
	void move();
	void setPosition(Vector2f pos);
	Vector2f getPosition();
	View getView();
	PlayerToken();
	~PlayerToken();
};