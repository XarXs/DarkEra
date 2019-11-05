#include "MapBC.h"

Mapa::Mapa(){
	textura = new Texture();
	if (!textura->loadFromFile("Texture/textures.jpg")){
		cout << "error\n";
	}
	sprite = new Sprite();
	sprite->setTexture(*textura);
	okno = MainWindow::getMainWindow()->getWindow();
	fov = 3;
	obj = new Object();

	map = NULL;
}

Mapa::~Mapa(){
	delete textura;
	delete sprite;
	for (int i = 0; i < mSzer; i++)	delete[]map[i];
	delete []map;
	delete obj;
}

void Mapa::render(){
	for (int i = 0; i < mSzer; i++){
		for (int j = 0; j < mWys; j++){
			if (map[i][j] >= 3){
				if (map[i][j] == 3) sprite->setColor(Color::Black);
				else if (map[i][j] == 4) sprite->setColor(Color(100, 100, 100, 255));
				else if (map[i][j] == 5) sprite->setColor(Color::White);
				sprite->setTextureRect(IntRect(109, 216, TEXSIZE, TEXSIZE));
			}
			else{
				if (map[i][j] == 2){
					sprite->setColor(Color::White);
				}
				else if (map[i][j] == 1){
					sprite->setColor(Color(100, 100, 100, 255));
				}
				else if(map[i][j] == 0){
					sprite->setColor(Color::Black);
				}
				sprite->setTextureRect(IntRect(109, 324, TEXSIZE, TEXSIZE));
			}
			sprite->setPosition(i * (TEXSIZE), j * (TEXSIZE));
			okno->draw(*sprite);
		}
	}//end of loop

	obj->render();
}

void Mapa::generateMap(){
	/*
	Mapa jest generowania metodą spacerkową.
	Spacer ma ograniczoną liczbę tuneli o ograniczonej długości
	każdy tunel jest w innym kierunku
	*/
	if (!map){
		for (int i = 0; i < mSzer; i++)	delete[]map[i];
		delete[]map;
	}
	mWys = (rand() % 30) + 25;
	mSzer = (rand() % 30) + 25;

	cout << mWys << " " << mSzer << endl;
	map = new int *[mSzer];
	for (int i = 0; i < mSzer; i++){
		map[i] = new int[mWys];
	}
	for (int i = 0; i < mSzer; i++){
		for (int j = 0; j < mWys; j++){
			map[i][j] = 3;
		}
	}//end of loop


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

	//setting objects on map
	Vector2f pos;
	do{
		pos.y = (rand() % (mWys - 3)) + 1;
		pos.x = (rand() % (mSzer - 3)) + 1;
		if (pos.x == beginning.x && pos.y == beginning.y) continue;
		if (pos.y * TEXSIZE >= mSzer * TEXSIZE) continue;
		if (pos.x * TEXSIZE >= mWys * TEXSIZE) continue;
	} while (map[(int)pos.x][(int)pos.y] == 3);
	pos.x = pos.x * TEXSIZE + 25;
	pos.y = pos.y * TEXSIZE + 25;
	cout << pos.x << " " << pos.y << endl;
	obj->setPosition(pos);
}//koniec metody

Vector2f Mapa::getPos(){
	return beginning;
}//koniec metody

Vector2i Mapa::getPosInt(){
	return Vector2i(beginning.x, beginning.y);
}

bool Mapa::collision(PlayerToken& token){
	Vector2i size = token.getSize();
	Vector2i position((token.getPosition().x + 10) / TEXSIZE, (token.getPosition().y + 5) / TEXSIZE);
	Vector2i position2((token.getPosition().x + size.x) / TEXSIZE, (token.getPosition().y + size.y) / TEXSIZE);
	Vector2i position3((token.getPosition().x ) / TEXSIZE, (token.getPosition().y + size.y) / TEXSIZE);
	Vector2i position4((token.getPosition().x + size.x) / TEXSIZE, (token.getPosition().y) / TEXSIZE);
	
	this->shadowCast(position);
	
	if (map[position.x][position.y] >= 3) return true;
	if (map[position2.x][position2.y] >= 3) return true;
	if (map[position3.x][position3.y] >= 3) return true;
	if (map[position4.x][position4.y] >= 3) return true;
	return false;
}//koniec metody

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
			if (map[i][j] == 2) map[i][j] = 1;
			else if (map[i][j] == 5) map[i][j] = 4;
		}
	}//end of loop

	//widzimy w prawo
	for (int i = 0; i < fov; i++){
		if (map[playerPos.x + i][playerPos.y] >= 3){
			map[playerPos.x + i][playerPos.y] = 5;
			break;
		}else map[playerPos.x + i ][playerPos.y] = 2;
	}

	//widzimy w dół
	for (int i = 0; i < fov; i++){
		if (map[playerPos.x][playerPos.y + i] >= 3){
			map[playerPos.x][playerPos.y + i] = 5;
			break;
		}else map[playerPos.x][playerPos.y + i] = 2;
	}

	//widzimy w lewo
	for (int i = 0; i < fov; i++){
		if (map[playerPos.x - i][playerPos.y] >= 3){
			map[playerPos.x - i][playerPos.y] = 5;
			break;
		}
		else map[playerPos.x - i][playerPos.y] = 2;
	}

	//widzimy w górę
	for (int i = 0; i < fov; i++){
		if (map[playerPos.x][playerPos.y - i] >= 3){
			map[playerPos.x][playerPos.y - i] = 5;
			break;
		}
		else map[playerPos.x][playerPos.y - i] = 2;
	}
	//ukosy
	// prawy w dół
	for (int i = 0; i < fov - 1; i++){
		if (map[playerPos.x + i][playerPos.y + i] >= 3){
			map[playerPos.x + i][playerPos.y + i] = 5;
			break;
		}
		else map[playerPos.x + i][playerPos.y + i] = 2;
	}
	//lewy w górę
	for (int i = 0; i < fov - 1; i++){
		if (map[playerPos.x - i][playerPos.y - i] >= 3){
			map[playerPos.x - i][playerPos.y - i] = 5;
			break;
		}
		else map[playerPos.x - i][playerPos.y - i] = 2;
	}
	//prawy górny
	for (int i = 0; i < fov - 1; i++){
		if (map[playerPos.x + i][playerPos.y - i] >= 3){
			map[playerPos.x + i][playerPos.y - i] = 5;
			break;
		}
		else map[playerPos.x + i][playerPos.y - i] = 2;
	}
	//lewy dół
	for (int i = 0; i < fov - 1; i++){
		if (map[playerPos.x - i][playerPos.y + i] >= 3){
			map[playerPos.x - i][playerPos.y + i] = 5;
			break;
		}
		else map[playerPos.x - i][playerPos.y + i] = 2;
	}
}

void Mapa::update(PlayerToken &token){
	Vector2i position((token.getPosition().x + 10) / TEXSIZE, (token.getPosition().y + 5) / TEXSIZE);
	if (position.x == (int)(obj->getPostion().x / TEXSIZE) && position.y == (int)(obj->getPostion().y / TEXSIZE)){
		if (obj->interaction(this)){
			token.setPosition(Vector2f(this->getPos().x * 108 + (rand() % 25 + 20), this->getPos().y * 108 + (rand() % 25 + 20)));
			position = Vector2i((token.getPosition().x + 10) / TEXSIZE, (token.getPosition().y + 5) / TEXSIZE);
			this->shadowCast(position);
		}
	}
}