#include "Player.h"

Player::Player(){
	hp = 100;
	mp = 0;
	speed = 10;

	texture = new Texture();
	if (!texture->loadFromFile("Graphics/kapitan_overkill.png")){
		cout << "Error: Player texture not found\n";
		exit(0);
	}

	sprite = new Sprite(*texture);
	sprite->setScale(Vector2f(0.5, 0.5));
	x = sprite->getPosition().x;
	y = sprite->getPosition().y;
}

Player::Player(int hp, int mp, int speed, int x, int y, string source){
	this->hp = hp;
	this->mp = mp;
	this->speed = speed;
	this->x = x;
	this->y = y;

	texture = new Texture();
	if (!texture->loadFromFile(source)){
		cout << "Error: Player texture not found\n";
		exit(0);
	}

	sprite = new Sprite(*texture);
	sprite->setScale(Vector2f(0.5, 0.5));
	sprite->setPosition(Vector2f(x, y));
}

Player::~Player(){
	delete texture;
	delete sprite;
}

void Player::draw(){
	MainWindow::getMainWindow()->getWindow()->draw(*sprite);
}

void Player::move(){
	if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)){
		x -= speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)){
		x += speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)){
		y -= speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)){
		y += speed;
	}

	sprite->setPosition(Vector2f(x, y));
}