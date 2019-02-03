/*
Menu główne gry, które pojawia się zaraz po uruchomieniu aplikacji.
W nim są zawarte następujące opcje:
-Nowa Gra - Tworzy rozgrywkę z nową postacią, zaczynając od samego początku
-Wczytaj Grę - Jeśli jest zapisana jakaś rozgrywka, umożliwia rozpoczęcie gry od momentu, który został zapisany
-Opcje - Możliwość dostosowania trybu widoku (okno, pełen ekran), głośność dźwięków SF, głośność muzyki, głośność ogólna
-Wyjście - Umożliwia zamknięcie aplikacji
*/
#pragma once
#include "Biblioteki.h"

class MainMenu{
private:
	int targetOption;//zaznaczona opcja;
	Text* text;		//wypisywane możliwe opcje
	bool run;		//czy jest uruchumione menu, na początku true
	RenderWindow* okno;
public:

	void runMenu();		//pętla menu
	void draw();	//rysowanie menu
	void moveUp();	//poruszanie się do góry menu
	void moveDown();//poruszanie się do dołu menu
	void enter();	//wciśnięcie entera
	MainMenu();
	~MainMenu();
};