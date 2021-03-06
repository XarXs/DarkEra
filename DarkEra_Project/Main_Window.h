/*G³ówne okno w postaci singletonu
zawiera okno gry przez co powinno w przysz³oœci ³atwiej dodawaæ nowe
elementy
*/
#pragma once
#include "Biblioteki.h"

class MainWindow{
	friend class Camera;
private:
	/*adres do singletonu*/
	static MainWindow* instance;
	/*prywatny konstruktor domyœlny do zapobiegania powstawaniu nowych instancji*/
	MainWindow();

	//obiekty g³ównego okna

	RenderWindow *window;
	Music *music;
	Font font;
	Camera *camera;
public:
	/*Dostêp do instancji okna*/
	static MainWindow* getMainWindow();

	/*Dostêp do g³ównego okna*/
	RenderWindow* getWindow();

	void setMusic(string source);	//ustawienie granej muzyki
	void playMusic();				//włączenie odtwarzanie muzyki
	void stopMusic();				//wyłączenie odtwarzanej muzyki
	void setValue(int value);		//ustawienie głośności
	int getValue();					//aktualna głośność

	void setFont(string source);	//ustaw czcionkę
	Font* getFont();					//pobranie adresu czcionki

	Camera* getCamera();		//pobieranie adresu kamery.
	~MainWindow();
};
