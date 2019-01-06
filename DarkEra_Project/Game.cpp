#include "Game.h"

Game::Game(){
	okno = MainWindow::getMainWindow()->getWindow();
	mainMenu = new MainMenu();
}
Game::~Game(){
	cout << "destructor Game\n";
	delete mainMenu;
	delete okno;
	delete MainWindow::getMainWindow();
}
void Game::proccesEvents(){
	Event events;
	while (okno->pollEvent(events)){

		switch (events.type){
		case Event::Closed:
			okno->close();
			break;
		}
	}
}

void Game::update(){

}

void Game::render(){
	//czyszczenie ekranu
	okno->clear();
	
	//rysowanie poszczególnych elementów
	mainMenu->draw();
	//wyœwietlanie
	okno->display();
}

void Game::run(){
	while (okno->isOpen()){
		proccesEvents();
		update();
		render();
	}
}