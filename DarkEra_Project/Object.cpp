#include "Object.h"

Object::Object(){
	renderable = false;
	Id = 0;
	name = "none";
	okno = MainWindow::getMainWindow()->getWindow();
	sprite = new Sprite(*TextureHandler::getTextureHandler()->getTexture("Texture/default.png"));
	sprite->setPosition(0, 0);
	sprite->setScale(SCALE, SCALE);
}

Object::Object(int Id, string name, Vector2f position, string tex){
	this->Id = Id;
	this->name = name;
	sprite = new Sprite(*TextureHandler::getTextureHandler()->getTexture(tex));
	sprite->setPosition(position);

	okno = MainWindow::getMainWindow()->getWindow();
}

Object::~Object(){
	okno = NULL;
	delete sprite;
}

//========================
void Object::render(){
	if (renderable)
		okno->draw(*sprite);
}

void Object::setPosition(Vector2f pos){
	sprite->setPosition(pos);
}

Vector2f Object::getPostion(){
	return sprite->getPosition();
}

void Object::setSprite(string tex){
	delete sprite;
	sprite = new Sprite(*TextureHandler::getTextureHandler()->getTexture(tex));
	sprite->setScale(Vector2f(SCALE, SCALE));
}

void Object::setSprite(Texture tex){
	delete sprite;
	sprite = new Sprite(tex);
	sprite->setScale(Vector2f(SCALE, SCALE));
}

void Object::setName(string name){
	this->name = name;
}

string Object::getName(){
	return name;
}

Texture Object::getTexture(){
	return *sprite->getTexture();
}

void Object::setId( int Id){
	this->Id = Id;
}

int Object::getId(){
	return Id;
}

void Object::interaction(){
	
}

bool Object::interaction(Mapa *map){
	return false;
}
void Object::interaction(Player *player){
	
}