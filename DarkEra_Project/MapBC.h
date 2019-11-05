/*
Bazowa klasa map.
W podstawowej formie zawiera metody odpowiedzialne za rysowanie mapy, określania
kolizji a także generowanie mapy.
*/
#pragma once
#include "Biblioteki.h"

class Mapa{
	friend class PlayerToken;
	friend class Object;
private:
	RenderWindow* okno; //alias do singletonu
	Texture* textura;	//textura zawierająca wszystkie elementy mapy
	Sprite* sprite;		//wyświetlany fragment tekstury
	int** map;			//wskaźnik na dwuwymiarową mapę
	int mWys;			//wysokość mapy
	int mSzer;			//szerokość mapy
	int fov;			//jak daleko widzi postać
	Vector2f beginning;
	Object *obj;
public:
	void render();
	virtual void generateMap();	//metoda wirutalna generująca mapa o wysokości 'w' i szerokości 's'
	virtual bool collision(PlayerToken &token);	//metoda wirtualna informująca o kolziji ze ścianami.
	void shadowCast(Vector2i playerPos);
	virtual void update(PlayerToken &token);
	Vector2f getPos();
	Vector2i getPosInt();
	Mapa();
	~Mapa();
};
