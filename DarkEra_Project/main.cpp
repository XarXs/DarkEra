#include "Biblioteki.h"
#include <cmath>
int main()
{
	srand(time(NULL));
	Game *gra = new Game();
	gra->run();
	delete gra;
	return 0;
}