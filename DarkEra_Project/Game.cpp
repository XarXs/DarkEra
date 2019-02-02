#include "Game.h"

// Konstruktor
Game::Game(){
	okno = MainWindow::getMainWindow()->getWindow();
	mainMenu = new MainMenu();
}

// Destruktor
Game::~Game(){
	cout << "destructor Game\n";
	delete mainMenu;
	delete okno;
	delete MainWindow::getMainWindow();
}


void Game::run(){
	// Główna pętla gry
	mainMenu->runMenu();

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
	
	//wyświetlanie
	okno->display();
}
