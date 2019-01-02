#include "Biblioteki.h"
#include <cmath>
int main()
{
	Game *gra = new Game();
	gra->run();
	delete gra;
	return 0;
}