#pragma once
#include "Biblioteki.h"

/* 
Klasa bazowa do ogólnie pojętych obiektów.
*/

class Object{
	friend class Mapa;
	friend class Player;
private:
	int Id;				//id - numer obiektu na mapie. Ułatwi wyszukiwanie;
	string name;		//name - nazwa obiektu
	RenderWindow* okno;	//dostęp do adresu okna
	Sprite* sprite;		//wyświetlany sprite obiektu
public:
	bool renderable;	//czy obiekt może zostać renderowany?
	void render();		//renderownie obiektu na mapie
	void setPosition(Vector2f pos);	//ustawianie pozycji
	Vector2f getPostion();	//getter pozycji
	void setName(string name);		//setter nazwy;
	void setSprite(string tex);
	void setSprite(Texture tex);
	string getName();
	Texture getTexture();
	void setId( int Id);
	int getId();
	virtual void interaction();	//metoda określajaca interakcję typu void
	virtual bool interaction(Mapa *map);	//metoda wchodząca w interakcję z mapą
	virtual void interaction(Player *player);	//metoda wchodząca w interakcję z graczem
	Object();
	Object(int Id, string name, Vector2f position, string tex);
	~Object();
};

class Key :public Object{
	friend class Player;
private:
	
public:
	void interaction(Player *player);

	Key();
	Key(Key &key, string tex);
};