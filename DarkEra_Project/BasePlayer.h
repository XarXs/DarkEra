#pragma once
#include "Biblioteki.h"

class BasePlayer{
private:
	Sprite* sp;	//wyświetlany sprite
	Texture* tx; //textura bohatera

	int speed;	//prędkość poruszania
	Vector2f position;	//pozycja gracza
public:
	void draw();	//rysowanie spritu
	virtual void move();	//poruszanie się
	void setPosition(int x, int y);	//ustawianie pozycji gracza
	void setPosition(Vector2f v);	//ustawianie pozycji gracza

	BasePlayer();
	~BasePlayer();
};