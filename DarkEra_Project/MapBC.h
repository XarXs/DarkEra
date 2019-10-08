/*
Bazowa klasa map.
W podstawowej formie zawiera metody odpowiedzialne za rysowanie mapy, określania
kolizji a także generowanie mapy.
*/
#pragma once
#include "Biblioteki.h"

class Mapa{
	friend class PlayerToken;
private:
	RenderWindow* okno; //alias do singletonu
	Texture* textura;	//textura zawierająca wszystkie elementy mapy
	Sprite* sprite;		//wyświetlany fragment tekstury
	int** map;			//wskaźnik na dwuwymiarową mapę
	int mWys;			//wysokość mapy
	int mSzer;			//szerokość mapy
	Vector2f beginning;
public:
	void render();
	virtual void generateMap();	//metoda wirutalna generująca mapa o wysokości 'w' i szerokości 's'
	virtual bool collision(PlayerToken &token);	//metoda wirtualna informująca o kolziji ze ścianami.
	Vector2f getPos();
	Mapa();
	~Mapa();
};
