#pragma once
#include "Biblioteki.h"

class GameWindow{
private:
	static GameWindow* instance;	// statyczna instancja
	RenderWindow* window;		// element singletonu; Okno musi być tylko jedno, a będzie potrzebny na obszarze wszystkich class
	GameWindow();
public:
	static GameWindow* getInstance();	//metoda uzyskania dostępu do instancji
	RenderWindow* getWindow();		//metoda uzyskania dostępu do okna; Dostęp do tego zawsze po wcześniejszym uzyskaniu dostępu do instancji
	~GameWindow();
};
