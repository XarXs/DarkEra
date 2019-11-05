#include "Object.h"

Object::Object(){
	Id = 0;
	name = "none";
	okno = MainWindow::getMainWindow()->getWindow();
	color = Color::Magenta;
}

Object::~Object(){
	okno = NULL;
}

//========================
void Object::render(){
	RectangleShape tokeno(Vector2f(40, 40));
	tokeno.setPosition(position);
	tokeno.setFillColor(color);
	okno->draw(tokeno);
}

void Object::setPosition(Vector2f pos){
	position = pos;
}

Vector2f Object::getPostion(){
	return position;
}

void Object::interaction(){
	
}

bool Object::interaction(Mapa *map){
	if (Keyboard::isKeyPressed(Keyboard::F)){
		map->generateMap();
		return true;
	}
	return false;
}