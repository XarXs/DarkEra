#include "MapBC.h"

Mapa::Mapa(){
	textura = new Texture();
	if (!textura->loadFromFile("Texture/textures.jpg")){
		cout << "error\n";
	}
	sprite = new Sprite();
	sprite->setTexture(*textura);
	okno = MainWindow::getMainWindow()->getWindow();
	mWys = (rand() % 30) + 25;
	mSzer = (rand() % 30) + 25;
	map = new int * [mSzer];
	for (int i = 0; i < mSzer; i++){
		map[i] = new int[mWys];
	}
	for (int i = 0; i < mSzer; i++){
		for (int j = 0; j < mWys; j++){
		map[i][j] = 1;
		}
	}//end of loop
}

Mapa::~Mapa(){
	delete textura;
	delete sprite;
	for (int i = 0; i < mSzer; i++)	delete[]map[i];
	delete []map;
}

void Mapa::render(){
	for (int i = 0; i < mSzer; i++){
		for (int j = 0; j < mWys; j++){
			if (map[i][j] == 1){
				sprite->setTextureRect(IntRect(109, 216, 108, 108));
			}
			else{
				sprite->setTextureRect(IntRect(109, 324, 108, 108));
			}
			sprite->setPosition(i * (108), j * (108));
			okno->draw(*sprite);
		}
	}//end of loop
}

void Mapa::generateMap(){
	/*
	Mapa jest generowania metodą spacerkową.
	Spacer ma ograniczoną liczbę tuneli o ograniczonej długości
	każdy tunel jest w innym kierunku
	*/
	int maxTunnels = (rand() % 100) + 50;
	int maxLength = (rand() % 10) + 5;

	//początkowy losowy punkt, z którego rozpoczeni się generowanie mapy
	int currentRow = (rand() % mWys -1 ) +1;
	int currentColumn = (rand() % mSzer -1) +1;

	beginning.x = currentColumn;
	beginning.y = currentRow;

	//kierunki przemieszczania zapisane w tablicy by można było je losować
	Vector2i directions[4] = {
		Vector2i(-1, 0),
		Vector2i(1, 0),
		Vector2i(0, -1),
		Vector2i(0, 1)
	};
	Vector2i lastDirection = Vector2i(0, 0);
	Vector2i randomDirection = Vector2i(0, 0);

	//generowanie mapy
	while (maxTunnels && maxLength){
		do{
			randomDirection = directions[rand() % 4];
		} while ( (randomDirection.x == -lastDirection.x && randomDirection.y == -lastDirection.y)
			|| (randomDirection.x == lastDirection.x && randomDirection.y == lastDirection.y));
		
		int randomLength = (rand() % maxLength) + 1;	//losowa długość tunelu
		int tunnelLength = 0;

		while (tunnelLength < randomLength){

			//przerwij pętle jeśli ma wyjść poza tablicę
			if (
				((currentRow == 1) && (randomDirection.y == -1)) ||
				((currentColumn == 1) && (randomDirection.x == -1)) ||
				((currentRow == mWys - 2) && (randomDirection.y == 1)) ||
				((currentColumn == mSzer - 2) && (randomDirection.x == 1))
				){
				break;
			}
			else{
				map[currentColumn][currentRow] = 0;
				currentRow += randomDirection.y;
				currentColumn += randomDirection.x;
				tunnelLength++;
			}//koniec ifa
		}//koniec pętli

		if (tunnelLength){
			lastDirection = randomDirection;
			maxTunnels--;
		}
	}//koniec pętli zewnętrznej
}//koniec metody

Vector2f Mapa::getPos(){
	return beginning;
}