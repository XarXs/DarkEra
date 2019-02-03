#include "MapBC.h"

Mapa::Mapa(){
	textura = new Texture();
	sprite = new Sprite();
	okno = MainWindow::getMainWindow()->getWindow();
}

Mapa::~Mapa(){
	delete textura;
	delete sprite;
}

void Mapa::render(){
	okno->draw(*sprite);
}