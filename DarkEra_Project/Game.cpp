#include "Game.h"

// Konstruktor
Game::Game(){
	okno = MainWindow::getMainWindow()->getWindow();
	mainMenu = new MainMenu();
	player = new Player();
}

// Destruktor
Game::~Game(){
	cout << "destructor Game\n";
	delete mainMenu;
	delete okno;
	delete player;
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
	player->move();
}

// Renderowanie 
void Game::render(){
	//czyszczenie ekranu
	okno->clear();

	//rysowanie poszczególnych elementów
	player->draw();

	//wyświetlanie
	okno->display();
}
