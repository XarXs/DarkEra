/*
klasa odpowiadająca za podstawowe ustawienia gry, jakie może modyfikować gracz.
To jest przede wszystkim głośność muzyki oraz efektów dźwiękowych.
Tutaj również powinien być przedstawione sterowanie w grze*/
#pragma once
#include "Biblioteki.h"

class Options{
	friend class MainMenu;
private:
	RenderWindow* okno;
	string pom;
	Text *text;
	int volume;	//głośność dźwięku
	bool on;	//czy opcje są otwarte, standardowo tak
	void render();//rysowanie
public:
	void run();	//uruchumienie panelu opcji
	void left();	//zmniejszanie wartości
	void right();	//zwiększanie wartości

	Options();
	~Options();
};