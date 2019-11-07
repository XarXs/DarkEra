#include "PlayerBC.h"
Token::Token(){
	position = Vector2f(0, 0);
	speed = 8;
	okno = MainWindow::getMainWindow()->getWindow();
	sprite = new Sprite(*TextureHandler::getTextureHandler()->getTexture("Texture/player.png"));
	sprite->setScale(SCALE, SCALE);
	name = "noneName";
	size = Vector2i(TextureHandler::getTextureHandler()->getTexture("Texture/player.png")->getSize().x * SCALE, TextureHandler::getTextureHandler()->getTexture("Texture/player.png")->getSize().y * SCALE);

}

Token::Token(string name, Vector2f position, string tex, int speed, Vector2f scale){
	this->name = name;
	this->position = position;
	this->speed = speed;

	center = Vector2f(position.x + (float)floor(size.x / 2), position.y + (float)floor(size.y / 2));

	okno = MainWindow::getMainWindow()->getWindow();
	this->tex = new Texture();
	if (!this->tex->loadFromFile(tex)){
		string e = "PlayerToken error: don't found file - " + tex + "/n";
		throw e;
	}
	size = Vector2i(this->tex->getSize().x * SCALE, this->tex->getSize().y * SCALE);
	sprite = new Sprite(*this->tex);
	sprite->setScale(scale);
}

Token::~Token(){
	okno = NULL;
	delete sprite;
	delete tex;
}

void Token::render(){
	okno->draw(*sprite);
}

void Token::move( Mapa& map){

	/*ruch do góry*/
	if (Keyboard::isKeyPressed(Keyboard::Up)){
		position.y += speed * (-1);
		if (map.collision(*this)) position.y -= speed * (-1);
	}
	/*ruch do dołu*/
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
	this->setPosition(position);
	MainWindow::getMainWindow()->getCamera()->update(position, Vector2i(map.mSzer, map.mWys));
} // koniec metody

void Token::setPosition(Vector2f pos){
	position = pos;
	center = Vector2f(position.x + (float)floor(size.x / 2), position.y + (float)floor(size.y / 2));
	sprite->setPosition(position);
}

void Token::setSize(Vector2i size){
	this->size = size;
}


void Token::setName(string name){
	this->name = name;
}

void Token::setSprite(string tex){
	Texture tx;

	if (tx.loadFromFile(tex)){
		this->tex->loadFromFile(tex);
		sprite->setTexture(*this->tex);
		size = Vector2i(this->tex->getSize().x * scale.x, this->tex->getSize().y * scale.y);
	}
}

void Token::setScale(Vector2f scale){
	sprite->setScale(scale);
	this->scale = scale;
}

void Token::setSpeed(int speed){
	this->speed = speed;
}

Vector2f Token::getPosition(){
	return position;
}

Vector2i Token::getSize(){
	return size;
}

Vector2f Token::getCenter(){
	return center;
}

string Token::getName(){
	return name;
}