#include "Game.h"

// Konstruktor
Game::Game(){
	okno = MainWindow::getMainWindow()->getWindow();
	mainMenu = new MainMenu();
	map = new Mapa();
	map->generateMap();
}

// Destruktor
Game::~Game(){
	cout << "destructor Game\n";
	delete mainMenu;
	delete map;
	delete okno;
	delete MainWindow::getMainWindow();
}


void Game::run(){
	// Główna pętla gry
	mainMenu->runMenu();
	cout << "Game Loop\n";
	while (okno->isOpen()){
		proccesEvents();
		update();
		render();
	}
}

// Wydarzenia
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

// Aktualizacja
void Game::update(){

}

// Renderowanie 
void Game::render(){
	//czyszczenie ekranu
	okno->clear();
	//rysowanie poszczególnych elementów
	map->render();
	//wyświetlanie
	okno->display();
}
