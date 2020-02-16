#include "Object.h"

Key::Key(){
	Object::setSprite("key.png");
	Object::setName("Klucz");
	Object::setId(1);
}

Key::Key(Key &key, string tex){
	setSprite(tex);
	setName(key.getName());
	setId(key.getId());
}

void Key::interaction(Player *player){
	
	player->pickUp(*this);
}