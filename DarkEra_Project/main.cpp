#include "Biblioteki.h"
int main()
{
	srand(time(NULL));
	try{
		Game *gra = new Game();
		gra->run();
		delete gra;
	}
	catch (string e){
		cout << e << endl;
		return 0;
	}
	return 0;
}