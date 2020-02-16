#include "PlayerBC.h"

Player::Player(string name, int hp, int atack, int def, Vector2f position, string tex, int speed, Vector2f scale){
	Player::Token(name, hp, atack, def, position, tex, speed, scale);
	Player::Token::setName(name);
	Player::Token::setPosition(position);
	Player::Token::setScale(scale);
	Player::Token::setSprite(tex);
	Player::Token::setSpeed(speed);
	maxHP = hp;
	hpBar.setSize(Vector2f(100, 20));
	hpBar.setFillColor(Color::Red);
	hpBar.setPosition(25, 25);

	eq = new Inventory();
}

Player::~Player(){
	delete eq;
}

bool Player::interaction(Object &obj){
	if (Keyboard::isKeyPressed(Keyboard::F)) {
		obj.interaction(this);
		return true;
	}
	return false;
}

void Player::pickUp(Object &obj){
	eq->addItem(obj);
}

void Player::HudRender(){
	View view;
	view.setViewport(FloatRect(0, 0, 1, 1));
	MainWindow::getMainWindow()->getWindow()->setView(view);
	MainWindow::getMainWindow()->getWindow()->draw(hpBar);
}

void Player::render(){
	Token::render();
	eq->render();
	this->HudRender();
}