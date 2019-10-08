#include "PlayerBC.h"
PlayerToken::PlayerToken(){
	position = Vector2f(0, 0);
	size = Vector2i(40, 40);
	speed = 8;
	okno = MainWindow::getMainWindow()->getWindow();
}
PlayerToken::~PlayerToken(){
}

void PlayerToken::render(){
	RectangleShape tokeno(Vector2f(40, 40));
	tokeno.setFillColor(Color::Cyan);
	tokeno.setPosition(position);
	okno->draw(tokeno);
}

void PlayerToken::move( Mapa& map){

	if (Keyboard::isKeyPressed(Keyboard::Up)){
		position.y += speed * (-1);
		if (map.collision(*this)) position.y -= speed * (-1);
	}
	/*ruch do tyłu*/
	if (Keyboard::isKeyPressed(Keyboard::Down)){
		position.y += speed * (1);
		if (map.collision(*this)) position.y -= speed * (1);
	}

	/*obrót w prawo*/
	if (Keyboard::isKeyPressed(Keyboard::Right)){
		position.x += speed * (1);
		if (map.collision(*this)) position.x -= speed * (1);
	}
	/*obrót w lewo*/
	if (Keyboard::isKeyPressed(Keyboard::Left)){
		position.x += speed * (-1);
		if (map.collision(*this)) position.x -= speed * (-1);
	}
	view.setCenter(position);
	view.setSize(900.f, 550.f);
	okno->setView(view);
	//this->setPosition(position);
}

void PlayerToken::setPosition(Vector2f pos){
	position = pos;
}

Vector2f PlayerToken::getPosition(){
	return position;
}

View PlayerToken::getView(){
	return view;
}

Vector2i PlayerToken::getSize(){
	return size;
}