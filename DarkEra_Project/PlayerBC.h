/*
Bazowa klasa postaci.
W podstawowej wersji zawiera metody odpowiedzialne za poruszanie się,
wyświetlanie wizerunku oraz będzie zawierać podstawowe statystyki.
*/

#pragma once
#include "Biblioteki.h"

class PlayerToken{
	friend class Mapa;
private:
	Vector2f position;			//aktualna pozycja gracza
	Vector2i size;				//rozmiar collision boxa; długość i szerokosć.
	int speed;
	RenderWindow* okno;
	View view;
public:
	void render();
	void move(Mapa& map);
	void setPosition(Vector2f pos);
	Vector2f getPosition();
	Vector2i getSize();
	View getView();
	PlayerToken();
	~PlayerToken();
};