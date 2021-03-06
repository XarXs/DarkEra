#pragma once
#include "Biblioteki.h"

class TextureHandler{
private:
	/*adres do singletonu*/
	static TextureHandler* instance;
	/*prywatny konstruktor domyœlny do zapobiegania powstawaniu nowych instancji*/
	TextureHandler();

	map<string, Texture*> tekstury;	//mapa tekstur, można wyszukiwac je przez ich ścieżki dostępu

	void addTexture(string source);

public:
	/*Dostêp do instancji okna*/
	static TextureHandler* getTextureHandler();

	Texture *getTexture(string source);
	
	~TextureHandler();
};
