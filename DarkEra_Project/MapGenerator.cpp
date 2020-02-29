#include "MapGenerator.h"


MapGenerator::MapGenerator()
{
}

int MapGenerator::generate(){
	const int x = ( rand() % 10 ) + 10;
	const int y = ( rand() % 10 ) + 10;
	int map[y][x];
	for (int i = 0; i < y; i++){
		for (int j = 0; j < x; j++){
			map[i][j] = 0;
			cout << map[i][j];
		}
		cout << endl;
	}

	return 1;
}


MapGenerator::~MapGenerator()
{
}
