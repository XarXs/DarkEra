#include"Game.h"

Game::Game(){
	cout << "|| GAME CONSTRUCTOR || \n";
	p = new BasePlayer;
}	//koniec konstruktora

Game::~Game(){
	cout << "|| GAME DESTRUCTOR ||\n";
	delete p;
	cout << endl;
}	//koniec destructora

void Game::run(){
	cout << "Runing main loop\n";

	//główna pętla gry
	while (GameWindow::getInstance()->getWindow()->isOpen()){
		this->Events();
		this->Update();
		this->Render();
	}	// koniec głównej pętli gry
	cout << " Exiting main loop\n";
}	// koniec metody

void Game::Events(){

	Event event;
	//sprawdzanie czy wystąpiły jakieś eventy
	while (GameWindow::getInstance()->getWindow()->pollEvent(event)){

		//zaprogramowanie guzika X, aby zamykał okno
		if (event.type == Event::Closed)
			GameWindow::getInstance()->getWindow()->close();
		if (event.type == Event::KeyReleased && event.key.code == Keyboard::Return)
			TextWriter::getInstance()->areaOnOff();
	} // koniec pętli while
}	//koniec metody

void Game::Update(){
	p->move();	//przesuwanie gracza

}	// koniec metody

void Game::Render(){
	//czyszczenie ekranu
	GameWindow::getInstance()->getWindow()->clear();

	//rysowanie elementów
	p->draw();
	String test = L"Test tekstu polskiego ąęćżź";
	TextWriter::getInstance()->render(test);
	//wyświetlanie obrazu
	GameWindow::getInstance()->getWindow()->display();
}	//koniec metody