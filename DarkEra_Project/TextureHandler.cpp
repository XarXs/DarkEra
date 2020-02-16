#include "TextureHandler.h"

TextureHandler::TextureHandler(){
}

TextureHandler::~TextureHandler(){
	cout << "Texture Handler destructor\n";
	map<string, Texture*>::iterator iter;
	cout << "Deleting tekstures\n";
	for (iter = tekstury.begin(); iter != tekstury.end(); ++iter){
		delete iter->second;
	}
	cout << "Deleting instance\n";
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
	string url = TEXTURE;
	url.append(source);

	if (tekstury.find(url) == tekstury.end()){
		addTexture(url);
	}
	return tekstury.find(url)->second;
}
