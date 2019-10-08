#include "BasePlayer.h"

BasePlayer::BasePlayer(){
	cout << "|| PLAYER CONSTRUCTOR || \n";
	tx = new Texture;

	// sprawdzenie czy udałos się załadować plik
	if (!tx->loadFromFile("Graphics/kapitan_overkill.png")){
		string wyj = "Error: Player graphics loading\n";
		delete tx;
		throw wyj;
	}

	sp = new Sprite(*tx);
	sp->setScale(Vector2f(0.5, 0.5));
	cout << " Player sprite setted\n";

	speed = 10;
	cout << "Player initial speed: " << speed<<endl;

	position.x = 0;
	position.y = 0;
	cout << "Player initila position: " << position.x << ", " << position.y << endl;
}	// koniec konstruktora

BasePlayer::~BasePlayer(){
	cout << "|| PLAYER DESTRUCTOR ||\n";
	delete tx;
	cout << "  texture deleted\n";
	delete sp;
	cout << "  sprite delted\n\n";
	cout << endl;
}	// koniec destruktora

void BasePlayer::draw(){
	GameWindow::getInstance()->getWindow()->draw(*sp);
}	// koniec metody

void BasePlayer::move(){
	//przesuwanie w prawo
	if (Keyboard::isKeyPressed(Keyboard::Right)){
		position.x += speed;
	}

	//przesuwanie w lew
	if (Keyboard::isKeyPressed(Keyboard::Left)){
		position.x -= speed;
	}

	//przesuwanie w górę
	if (Keyboard::isKeyPressed(Keyboard::Up)){
		position.y -= speed;
	}

	//przesuwanie w dół
	if (Keyboard::isKeyPressed(Keyboard::Down)){
		position.y += speed;
	}

	this->setPosition(position);
}	// koniec metody

void BasePlayer::setPosition(int x, int y){
	sp->setPosition(x, y);
}	// koniec metody

void BasePlayer::setPosition(Vector2f v){
	sp->setPosition(v);
}	// koniec metody