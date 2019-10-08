#include "Biblioteki.h"

int main(){
	try{
		Game *g = new Game;
		g->run();
		delete g;
	}
	catch (string w){
		cout << endl;
		cout << "==============================================\n";
		cout << "Exception " << w << endl;
	}

	delete TextWriter::getInstance();
	delete GameWindow::getInstance();
	return 0;
}