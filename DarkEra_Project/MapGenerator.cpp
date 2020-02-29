#include "MapGenerator.h"


MapGenerator::MapGenerator()
{
}

int MapGenerator::generate(){
	Vector2i size;
	size.x = ( rand() % 10 ) + 10;
	size.y = ( rand() % 10 ) + 10;
	int ** map = new int * [size.y];
	for (int y = 0; y < size.y; y++){
		map[y] = new int[size.x];
		for (int x = 0; x < size.x; x++){
			map[y][x] = 0;
			cout << map[y][x];
		}
		cout << endl;
	}

	return 1;
}


MapGenerator::~MapGenerator()
{
}
