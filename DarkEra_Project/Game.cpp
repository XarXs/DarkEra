#include "Game.h"

// Konstruktor
Game::Game(){
	okno = MainWindow::getMainWindow()->getWindow();
	mainMenu = new MainMenu();
	map = new Mapa();
	map->generateMap();
	player = new PlayerToken();
	player->setPosition(Vector2f(map->getPos().x * 108 + (rand() % 25 + 20), map->getPos().y * 108 + (rand() % 25 + 20)));
	map->shadowCast(map->getPosInt());
}

// Destruktor
Game::~Game(){
	cout << "destructor Game\n";
	delete mainMenu;
	delete map;
	delete player;
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
	player->move(*map);
	map->update(*player);
}

// Renderowanie 
void Game::render(){
	//czyszczenie ekranu
	okno->clear();
	//rysowanie poszczególnych elementów
	map->render();
	player->render();
	//wyświetlanie
	okno->display();
}
