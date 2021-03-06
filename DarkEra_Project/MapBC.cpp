#include "MapBC.h"

Mapa::Mapa(){

	sprite = new Sprite(*TextureHandler::getTextureHandler()->getTexture("Texture/textures.jpg"));
	okno = MainWindow::getMainWindow()->getWindow();
	fov = 3;
	Map = NULL;
}

Mapa::~Mapa(){
	delete sprite;
	for (int i = 0; i < mSzer; i++)	delete[]Map[i];
	delete []Map;
	okno = NULL;
}

void Mapa::render(){
	for (int i = 0; i < mSzer; i++){
		for (int j = 0; j < mWys; j++){
			if (Map[i][j] >= 3){
				if (Map[i][j] == 3) sprite->setColor(Color::Black);
				else if (Map[i][j] == 4) sprite->setColor(Color(100, 100, 100, 255));
				else if (Map[i][j] == 5) sprite->setColor(Color::White);
				sprite->setTextureRect(IntRect(109, 216, TEXSIZE, TEXSIZE));
			}
			else{
				if (Map[i][j] == 2){
					sprite->setColor(Color::White);
				}
				else if (Map[i][j] == 1){
					sprite->setColor(Color(100, 100, 100, 255));
				}
				else if(Map[i][j] == 0){
					sprite->setColor(Color::Black);
				}
				sprite->setTextureRect(IntRect(109, 324, TEXSIZE, TEXSIZE));
			}
			sprite->setPosition(i * (TEXSIZE), j * (TEXSIZE));
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

	if (Map){
		cout << "Usuwanie starej mapy\n";
		for (int i = 0; i < mSzer; i++)	delete[]Map[i];
		delete[]Map;
	}
	cout << "Losowanie rozmiaru mapy\n";
	mWys = (rand() % 40) + 15;
	mSzer = (rand() % 40) + 15;

	cout << "Tworzenie tablicy mapy\n";
	Map = new int *[mSzer];
	for (int i = 0; i < mSzer; i++){
		Map[i] = new int[mWys];
	}
	for (int i = 0; i < mSzer; i++){
		for (int j = 0; j < mWys; j++){
			Map[i][j] = 3;
		}
	}//end of loop

	cout << "Losowanie liczby tuneli i maksymalnejs dlugosci\n";
	int maxTunnels = (rand() % 100) + 50;
	int maxLength = (rand() % 10) + 5;

	//początkowy losowy punkt, z którego rozpoczeni się generowanie mapy
	cout << "Losowanie początkowego punktu generowania mapy\n";
	int currentRow = (rand() % mWys -1 ) +2;
	int currentColumn = (rand() % mSzer -1) +2;

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
	cout << "Generowanie mapy\n";
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
				((currentRow == mWys - 3) && (randomDirection.y == 1)) ||
				((currentColumn == mSzer - 3) && (randomDirection.x == 1))
				){
				cout << "Tunel wychodzi poza mapę\n";
				break;
			}
			else{
				cout << "Trwa spacer\n";
				Map[currentColumn][currentRow] = 0;
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
	cout << "Koniec generowania mapy\n";
}//koniec metody

Vector2f Mapa::getPos(){
	return beginning;
}//koniec metody

Vector2i Mapa::getPosInt(){
	return Vector2i(beginning.x, beginning.y);
}

Vector2i Mapa::getMapSize(){
	return Vector2i(mSzer, mWys);
}

bool Mapa::collision(Token& token){
	Vector2i size = token.getSize();
	Vector2i position(((token.getPosition().x) / TEXSIZE), ((token.getPosition().y + 5) / TEXSIZE ));
	Vector2i position2(((token.getPosition().x + size.x) / TEXSIZE),((token.getPosition().y + size.y) / TEXSIZE));
	Vector2i position3(((token.getPosition().x ) / TEXSIZE), ((token.getPosition().y + size.y + 5) / TEXSIZE));
	Vector2i position4(((token.getPosition().x + size.x) / TEXSIZE),((token.getPosition().y) / TEXSIZE));
	
	Vector2i ct(token.getCenter().x / TEXSIZE, token.getCenter().y / TEXSIZE);
	this->shadowCast(ct);

	if (Map[position.x][position.y] >= 3) return true;
	if (Map[position2.x][position2.y] >= 3) return true;
	if (Map[position3.x][position3.y] >= 3) return true;
	if (Map[position4.x][position4.y] >= 3) return true;
	return false;
}//koniec metody

int Mapa::collisionItems(Token& token){
	return 0;
}

void Mapa::shadowCast(Vector2i playerPos){
	/*
	0 - black; never been there
	1 - grey; visited
	2 - bright; actual field of view
	3 - wall
	*/

	//czyszczenie mapy z widocznych punktów;
	for (int i = 0; i < mSzer; i++){
		for (int j = 0; j < mWys; j++){
			if (Map[i][j] == 2) Map[i][j] = 1;
			else if (Map[i][j] == 5) Map[i][j] = 4;
		}
	}//end of loop

	//widzimy w prawo
	for (int i = 0; i < fov; i++){
		if (Map[playerPos.x + i][playerPos.y] >= 3){
			Map[playerPos.x + i][playerPos.y] = 5;
			break;
		}else Map[playerPos.x + i ][playerPos.y] = 2;
	}

	//widzimy w dół
	for (int i = 0; i < fov; i++){
		if (Map[playerPos.x][playerPos.y + i] >= 3){
			Map[playerPos.x][playerPos.y + i] = 5;
			break;
		}
		else Map[playerPos.x][playerPos.y + i] = 2;
	}

	//widzimy w lewo
	for (int i = 0; i < fov; i++){
		if (Map[playerPos.x - i][playerPos.y] >= 3){
			Map[playerPos.x - i][playerPos.y] = 5;
			break;
		}
		else Map[playerPos.x - i][playerPos.y] = 2;
	}

	//widzimy w górę
	for (int i = 0; i < fov; i++){
		if (Map[playerPos.x][playerPos.y - i] >= 3){
			Map[playerPos.x][playerPos.y - i] = 5;
			break;
		}
		else Map[playerPos.x][playerPos.y - i] = 2;
	}
	//ukosy
	// prawy w dół
	for (int i = 0; i < fov - 1; i++){
		if (Map[playerPos.x + i][playerPos.y + i] >= 3){
			Map[playerPos.x + i][playerPos.y + i] = 5;
			break;
		}
		else Map[playerPos.x + i][playerPos.y + i] = 2;
	}
	//lewy w górę
	for (int i = 0; i < fov - 1; i++){
		if (Map[playerPos.x - i][playerPos.y - i] >= 3){
			Map[playerPos.x - i][playerPos.y - i] = 5;
			break;
		}
		else Map[playerPos.x - i][playerPos.y - i] = 2;
	}
	//prawy górny
	for (int i = 0; i < fov - 1; i++){
		if (Map[playerPos.x + i][playerPos.y - i] >= 3){
			Map[playerPos.x + i][playerPos.y - i] = 5;
			break;
		}
		else Map[playerPos.x + i][playerPos.y - i] = 2;
	}
	//lewy dół
	for (int i = 0; i < fov - 1; i++){
		if (Map[playerPos.x - i][playerPos.y + i] >= 3){
			Map[playerPos.x - i][playerPos.y + i] = 5;
			break;
		}
		else Map[playerPos.x - i][playerPos.y + i] = 2;
	}
}

void Mapa::update(Player &token){

}

void Mapa::update(Token &token){

}