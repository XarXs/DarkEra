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
	delete map;
	delete player;
	okno = NULL;
	delete TextureHandler::getTextureHandler();
	delete MainWindow::getMainWindow();
}


void Game::run(){
	// Główna pętla gry
	cout << "Menu\n";
	mainMenu->runMenu();
	cout << "Creating LevelOne map\n";
	map = new LevelOne();
	cout << "====================== || Generating map || ======================\n";
	map->generateMap();
	cout << "============================================\nCreating Player\n";
	player = new Player("Kapitan Overkill", Vector2f(map->getPos().x * TEXSIZE + 5, map->getPos().y * TEXSIZE + 5), "Texture/player.png", 8, Vector2f(2.5, 2.5));
	cout << "ShadowCast\n";
	map->shadowCast(map->getPosInt());

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
