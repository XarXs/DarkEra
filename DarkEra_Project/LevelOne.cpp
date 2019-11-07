#include "MapBC.h"

void LevelOne::generateMap(){
	Mapa::generateMap();
	Key *key = new Key();
	int x;
	int y;
	do{
		x = (rand() % (getMapSize().x + 2)) - 2;
		y = (rand() % (getMapSize().y + 2)) - 2;

		if (x == getPosInt().x && y == getPosInt().y) continue;

	} while (Map[x][y] >= 3);

	key->setPosition(Vector2f(x * TEXSIZE + 25, y*TEXSIZE + 25));
	items[1] = key;
}

void LevelOne::update(Player &token){
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