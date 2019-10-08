#pragma once
#include "Biblioteki.h"

class TextWriter{
private:
	static TextWriter* instance;
	Text* tekst;
	Font* font;
	Texture* tx;
	Sprite* sp;
	Clock* c;
	Time* t;
	int transp;
	bool switcher;
	int it;
	Vector2f textStartPos;

	TextWriter();
public:
	static TextWriter* getInstance();	// dostęp do instancji singletonu
	void render(String& dialog);		// wyświetlanie okna dialogu
	void setPosition(Vector2f pos);		// ustawianie pozycji tekstu
	void spSetPostition(Vector2f pos);	// ustawianie pozycji sprite tła okna dialogu
	void spSetScale(Vector2f scale);	// ustawianie skalowania sprite tła okna dialogu
	void setColor(Color c);				// ustawianie koloru czcionki
	void tekstDisplayer(String &dialog);	// "wypisywanie" tekstu w oknie dialogu
	void areaOnOff();					// switcher wyświetlania/zanikania okna dialogu

	~TextWriter();
};