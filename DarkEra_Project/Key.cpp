#include "Object.h"

Key::Key(){
	Object::setSprite("Texture/key.png");
	Object::setName("Klucz");
	Object::setId(1);
}

Key::Key(Key &key, string tex){
	setSprite(tex);
	setName(key.getName());
	setId(key.getId());
}

bool Key::interaction(Player *player){
	if (Keyboard::isKeyPressed(Keyboard::F)) {
		player->pickUp(*this);
		return true;
	}
	return false;
}