/*
Bazowa klasa map.
W podstawowej formie zawiera metody odpowiedzialne za rysowanie mapy, określania
kolizji a także generowanie mapy.
*/
#pragma once
#include "Biblioteki.h"

class Mapa{
	friend class Token;
protected:
	int** Map;			//wskaźnik na dwuwymiarową mapę
	int fov;			//jak daleko widzi postać
private:
	RenderWindow* okno; //alias do singletonu
	Sprite* sprite;		//wyświetlany fragment tekstury
	int mWys;			//wysokość mapy
	int mSzer;			//szerokość mapy
	Vector2f beginning;
public:
	virtual void render();
	virtual void generateMap();	//metoda wirutalna generująca mapa o wysokości 'w' i szerokości 's'
	virtual bool collision(Token &token);	//metoda wirtualna informująca o kolziji ze ścianami.
	virtual int collisionItems(Token &token);
	virtual void shadowCast(Vector2i playerPos);	//metoda wirtualna która oświetla i zacienia mapę
	virtual void update(Player &token);	
	virtual void update(Token &token);
	Vector2f getPos();
	Vector2i getPosInt();
	Vector2i getMapSize();
	Mapa();
	~Mapa();
};

class LevelOne : public Mapa{
	friend class Key;
private:
	map<int, Object*> items;
	map<int, Object*>::iterator iter;
public:
	void render();
	void generateMap();
	void update(Player &token);
	int collisionItems(Token &token);
	void shadowCast(Vector2i playerPos);
};
