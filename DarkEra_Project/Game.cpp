#include "Game.h"

Game::Game(){
	okno = MainWindow::getMainWindow()->getWindow();
}
Game::~Game(){
	cout << "destructor Game\n";
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
	sf::CircleShape ksztalt(std::sin(stoper.getElapsedTime().asSeconds()) * okno->getSize().y / 8 + okno->getSize().y / 4);
	ksztalt.setOrigin(sf::Vector2f(ksztalt.getRadius(), ksztalt.getRadius()));
	ksztalt.setPosition(okno->getSize().x / 2.0f, okno->getSize().y / 2.0f);
	ksztalt.setFillColor(sf::Color::Yellow);
	okno->draw(ksztalt);
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