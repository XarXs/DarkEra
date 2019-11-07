#include "TextureHandler.h"

TextureHandler::TextureHandler(){
}

TextureHandler::~TextureHandler(){
	instance = NULL;
}

TextureHandler* TextureHandler::instance = 0;

TextureHandler*TextureHandler::getTextureHandler(){
	if (instance == 0)
		instance = new TextureHandler();
	return instance;
}

void TextureHandler::addTexture(string source){
	tekstury[source] = new Texture();
	if (!tekstury.find(source)->second->loadFromFile(source)){
		tekstury.erase(source);
		string e = "Error: don't found texture - source: " + source;
		throw e;
	}
}

Texture *TextureHandler::getTexture(string source){
	if (tekstury.find(source) == tekstury.end()){
		addTexture(source);
	}
	return tekstury.find(source)->second;
}
