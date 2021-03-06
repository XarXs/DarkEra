/*
Bazowa klasa postaci.
W podstawowej wersji zawiera metody odpowiedzialne za poruszanie się,
wyświetlanie wizerunku oraz będzie zawierać podstawowe statystyki.
*/

#pragma once
#include "Biblioteki.h"

class Token{
	friend class Mapa;
private:
	string name;
	Vector2f position;			//aktualna pozycja gracza; lewy górny róg sprite
	Vector2f center;			//centrum sprite
	Vector2i size;				//rozmiar collision boxa; długość i szerokosć.
	Vector2f scale;
	int speed;
	RenderWindow* okno;
	Sprite* sprite;		//wyświetlany sprite postaci
public:
	void virtual render();
	virtual void move(Mapa& map);
	void setPosition(Vector2f pos);
	void setSize(Vector2i size);

	void setName(string name);
	void setSprite(string tex);
	void setScale(Vector2f scale);
	void setSpeed(int speed);

	Vector2f getPosition();
	Vector2i getRelativePosition();	//zwraca pozycję gracza w przestrzeni tablicy mapy
	Vector2i getSize();
	Vector2f getCenter();

	string getName();

	Token();
	Token(string name, Vector2f position, string tex, int speed, Vector2f scale);
	~Token();
};

class Player : public Token{
	friend class Inventory;
private:
	Inventory* eq;
public:
	void pickUp(Object &obj);
	bool interaction(Object &obj);
	void render();

	Player(string name, Vector2f position, string tex, int speed, Vector2f scale);
	~Player();
};