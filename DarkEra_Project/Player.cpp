#include "PlayerBC.h"

Player::Player(string name, Vector2f position, string tex, int speed, Vector2f scale){
	Player::Token(name, position, tex, speed, scale);
	Player::Token::setName(name);
	Player::Token::setPosition(position);
	Player::Token::setScale(scale);
	Player::Token::setSprite(tex);
	Player::Token::setSpeed(speed);

	eq = new Inventory();
}

Player::~Player(){
	delete eq;
}

void Player::pickUp(Object obj){
	eq->addItem(obj);
}

void Player::render(){
	Token::render();
	eq->render();
}