#include "Object.h"

Object::Object(){
	Id = 0;
	name = "none";
	okno = MainWindow::getMainWindow()->getWindow();
	tex = new Texture();
	if (!tex->loadFromFile("Texture/default.png")){
		string e = "Object error: Don't found default texture\n";
		throw e;
	}
	sprite = new Sprite(*tex);
	sprite->setPosition(0, 0);
	sprite->setScale(SCALE, SCALE);
}

Object::Object(int Id, string name, Vector2f position, string tex){
	this->Id = Id;
	this->name = name;
	this->tex = new Texture();
	if (!this->tex->loadFromFile(tex)){
		string e = "Object error: Don't found default texture\n";
		throw e;
	}
	sprite = new Sprite(*this->tex);
	sprite->setPosition(position);

	okno = MainWindow::getMainWindow()->getWindow();
}

Object::Object(Object &obj){
	this->Id = obj.getId();
	this->name = obj.getName();
	this->tex = new Texture( obj.getTexture());
	sprite = new Sprite(*this->tex);
	sprite->setPosition(obj.getPostion());

	okno = MainWindow::getMainWindow()->getWindow();
}

Object::~Object(){
	okno = NULL;
	delete sprite;
	delete tex;
}

//========================
void Object::render(){
	okno->draw(*sprite);
}

void Object::setPosition(Vector2f pos){
	sprite->setPosition(pos);
}

Vector2f Object::getPostion(){
	return sprite->getPosition();
}

void Object::setSprite(string tex){
	Texture tx;
	
	if (tx.loadFromFile(tex)){
		this->tex->loadFromFile(tex);
		delete sprite;
		sprite = new Sprite(*this->tex);
		sprite->setScale(Vector2f(SCALE, SCALE));
	}
	else{
		string e = "error with loading texture for key! \n";
		throw(e);
	}
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
bool Object::interaction(Player *player){
	return false;
}