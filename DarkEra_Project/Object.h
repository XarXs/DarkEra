#pragma once
#include "Biblioteki.h"

/* 
Klasa bazowa do ogólnie pojętych obiektów.
*/

class Object{
	friend class Mapa;
private:
	int Id;				//id - numer obiektu na mapie. Ułatwi wyszukiwanie;
	string name;		//name - nazwa obiektu
	RenderWindow* okno;	//dostęp do adresu okna
public:
	void render();		//renderownie obiektu na mapie
	void setPosition(Vector2f pos);	//ustawianie pozycji
	Vector2f getPostion();	//getter pozycji
	//virtual void interaction();	//metoda określajaca interakcję typu void
	Object();
	~Object();
};