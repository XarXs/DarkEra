/*
Klasa bazowa postaci zawierające podstawowe metody, wspólne dla wszystkich kolejnych obiektów pochodnych.
Pionek powinien zawierać następujące atrybuty:
- HP
- MP/SP
- speed movement
*/
#pragma once
#include "Biblioteki.h"

class Player{
private:
	int hp;		//życie postaci
	int mp;		//mana/stamina postaci
	int speed;	//szybkość poruszania się
	int x, y;	//pozycja postaci (lewy górny róg)
	Texture *texture;	//textura postaci
	Sprite *sprite;		//wyświetlany obiekt graficzny postaci
public:
	void move();
	void draw();

	Player();
	~Player();
};