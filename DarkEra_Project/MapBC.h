/*
Bazowa klasa map.
W podstawowej formie zawiera metody odpowiedzialne za rysowanie mapy oraz określania
kolizji.
*/
#pragma once
#include "Biblioteki.h"

class Mapa{
private:
	RenderWindow* okno; //alias do singletonu
	Texture* textura;	//textura zawierająca wszystkie elementy mapy
	Sprite* sprite;		//wyświetlany fragment tekstury
public:
	void render();
	Mapa();
	~Mapa();
};
