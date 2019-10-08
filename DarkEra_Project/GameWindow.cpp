#include "GameWindow.h"

GameWindow* GameWindow::instance = NULL;

GameWindow::GameWindow(){
	cout << "|| GAMEWINDOW CONSTRUCTOR ||\n";
	window = new RenderWindow(VideoMode(Width, High), "DarkEra");
	window->setFramerateLimit(30);
	cout << " RenderWindow created\n";
}	// koniec konstruktora

GameWindow::~GameWindow(){
	static bool czy = true;
	if (czy){
		cout << "|| GAMEWINDOW DESTRUCTOR ||\n";
		delete window;
		cout << " window deleted\n";
		cout << endl;
	}
	czy = false;
}	// koniec destruktora

GameWindow* GameWindow::getInstance(){

	if (instance == NULL){	//sprawdzenie czy instancja już istnieje
		cout << "Createing new GameWindow instance\n";
		instance = new GameWindow();
	}
	return instance;
}	// koniec metody

RenderWindow* GameWindow::getWindow(){
	return window;
}	//koniec metody