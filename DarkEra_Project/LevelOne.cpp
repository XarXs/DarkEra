#include "MapBC.h"

void LevelOne::generateMap(){
	Mapa::generateMap();
	cout << "Tworzenie obiektu na mapie\n";
	Key *key = new Key();
	int x;
	int y;
	cout << "Losowanie pozycji obiektu\n";
	do{
		x = (rand() % (getMapSize().x + 2)) - 2;
		y = (rand() % (getMapSize().y + 2)) - 2;

		if (x == getPosInt().x && y == getPosInt().y) continue;

	} while (Map[x][y] >= 3);

	cout << "Ustawianie pozycji obiektu\n";
	key->setPosition(Vector2f(x * TEXSIZE + 25, y*TEXSIZE + 25));
	items[1] = key;
}

void LevelOne::shadowCast(Vector2i playerPos){
	Mapa::shadowCast(playerPos);

	//czyszczenie widoczności obiektów na mapie
	for (iter = items.begin(); iter != items.end(); ++iter){
			iter->second->renderable = false;
	}
	//szukanie przedmiotów, które znajdują się w polu widzenia
	//widzimy w prawo
	for (int i = 0; i < fov; i++){
		for (iter = items.begin(); iter != items.end(); ++iter){
			Vector2i item(iter->second->getPostion().x / TEXSIZE, iter->second->getPostion().y / TEXSIZE);
			if (playerPos.x + i == item.x &&
				playerPos.y == item.y){
				iter->second->renderable = true;
			}
		}
	}

	//widzimy w dół
	for (int i = 0; i < fov; i++){
		for (iter = items.begin(); iter != items.end(); ++iter){
			Vector2i item(iter->second->getPostion().x / TEXSIZE, iter->second->getPostion().y / TEXSIZE);
			if (playerPos.x == item.x &&
				playerPos.y + 1 == item.y){
				iter->second->renderable = true;
			}
		}
	}

	//widzimy w lewo
	for (int i = 0; i < fov; i++){
		for (iter = items.begin(); iter != items.end(); ++iter){
			Vector2i item(iter->second->getPostion().x / TEXSIZE, iter->second->getPostion().y / TEXSIZE);
			if (playerPos.x - i == item.x &&
				playerPos.y == item.y){
				iter->second->renderable = true;
			}
		}
	}

	//widzimy w górę
	for (int i = 0; i < fov; i++){
		for (iter = items.begin(); iter != items.end(); ++iter){
			Vector2i item(iter->second->getPostion().x / TEXSIZE, iter->second->getPostion().y / TEXSIZE);
			if (playerPos.x == item.x &&
				playerPos.y - i == item.y){
				iter->second->renderable = true;
			}
		}
	}
	//ukosy
	// prawy w dół
	for (int i = 0; i < fov - 1; i++){
		for (iter = items.begin(); iter != items.end(); ++iter){
			Vector2i item(iter->second->getPostion().x / TEXSIZE, iter->second->getPostion().y / TEXSIZE);
			if (playerPos.x + i == item.x &&
				playerPos.y + i == item.y){
				iter->second->renderable = true;
			}
		}
	}
	//lewy w górę
	for (int i = 0; i < fov - 1; i++){
		for (iter = items.begin(); iter != items.end(); ++iter){
			Vector2i item(iter->second->getPostion().x / TEXSIZE, iter->second->getPostion().y / TEXSIZE);
			if (playerPos.x - i == item.x &&
				playerPos.y - i == item.y){
				iter->second->renderable = true;
			}
		}
	}
	//prawy górny
	for (int i = 0; i < fov - 1; i++){
		for (iter = items.begin(); iter != items.end(); ++iter){
			Vector2i item(iter->second->getPostion().x / TEXSIZE, iter->second->getPostion().y / TEXSIZE);
			if (playerPos.x + i == item.x &&
				playerPos.y - i == item.y){
				iter->second->renderable = true;
			}
		}
	}
	//lewy dół
	for (int i = 0; i < fov - 1; i++){
		for (iter = items.begin(); iter != items.end(); ++iter){
			Vector2i item(iter->second->getPostion().x / TEXSIZE, iter->second->getPostion().y / TEXSIZE);
			if (playerPos.x - i == item.x &&
				playerPos.y + i == item.y){
				iter->second->renderable = true;
			}
		}
	}
}

void LevelOne::update(Player &token){
	this->shadowCast(token.getRelativePosition());
	int item = collisionItems(token);
	if (item){
		bool use = token.interaction(*items.find(item)->second);
		if (use) items.erase(item);
	}
}

int LevelOne::collisionItems(Token &token){
	Vector2i playerPos(token.getCenter().x / TEXSIZE, token.getCenter().y / TEXSIZE);
	for (iter = items.begin(); iter != items.end(); ++iter){
		Vector2i item(iter->second->getPostion().x / TEXSIZE, iter->second->getPostion().y / TEXSIZE);
		if (playerPos == item){
			return iter->first;
		}
	}
	return 0;
}

void LevelOne::render(){
	Mapa::render();
	if (!items.empty()){
		for (iter = items.begin(); iter != items.end(); ++iter){
			iter->second->render();
		}
	}
}