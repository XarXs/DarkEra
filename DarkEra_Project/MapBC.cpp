#include "MapBC.h"

Mapa::Mapa(){
	textura = new Texture();
	sprite = new Sprite();
	okno = MainWindow::getMainWindow()->getWindow();
	mWys = (rand() % 30) + 10;
	mSzer = (rand() % 30) + 10;
	*map = new int[mSzer];
	for (int i = 0; i < mSzer; i++){
		map[i] = new int[mWys];
	}
}

Mapa::~Mapa(){
	delete textura;
	delete sprite;
	for (int i = 0; i < mSzer; i++)	delete[]map[i];
	delete map;
}

void Mapa::render(){
	static int pp = 1;
	if (pp--){
		for (int i = 0; i < mSzer; i++){
			for (int j = 0; j < mWys; j++){
				cout << map[i][j];
			}
			cout << endl;
		}
	}
	//okno->draw(*sprite);
}

void Mapa::generateMap(){
	for (int i = 0; i < mSzer; i++){
		for (int j = 0; j < mWys; j++){
			map[i][j] = 1;
		}
	}
}