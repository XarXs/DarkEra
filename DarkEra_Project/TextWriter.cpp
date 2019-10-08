#include "TextWriter.h"

TextWriter* TextWriter::instance = NULL;

TextWriter::TextWriter(){
	font = new Font;
	if (!font->loadFromFile("Fonts/NewRocker-Regular.otf")){
		string wyj = "Error: Font upload problems\n";
		delete font;
		throw wyj;
	}
	tekst = new Text;
	tekst->setFont(*font);
	tekst->setFillColor(Color(255,255,255,0));

	tx = new Texture;
	if (!tx->loadFromFile("Graphics/podloze.png")){
		string wyj = "Error: TextWriter texture upload problems\n";
		delete font;
		throw wyj;
	}

	sp = new Sprite(*tx);
	sp->setScale(5.6, 1.3);
	sp->setColor(Color(255, 255, 255, 0));
	sp->setPosition(80, 450);
	c = new Clock;
	t = new Time;
	switcher = false;
	transp = 10;

	textStartPos.x = sp->getPosition().x + 25;
	textStartPos.y = sp->getPosition().y + 20;
	tekst->setPosition(textStartPos);
	it = 0;
}	// koniec konstruktora domyślnego

TextWriter::~TextWriter(){
	cout << "|| TEXT WRITER DESRUKTOR ||\n";
	delete tekst;
	cout << " Text is deleted\n";
	delete font;
	cout << " Font is deleted\n";
	delete sp;
	cout << " Sprite is deleted\n";
	delete tx;
	cout << " Texture is deleted\n";
	delete c;
	cout << " Clock is deleted\n";
}	// koniec destruktora

TextWriter* TextWriter::getInstance(){
	if (instance == NULL){
		cout << "Creating new Text Writer instance\n";
		instance = new TextWriter();
	}
	return instance;
}	// koniec metody

void TextWriter::render(String& dialog){
	static float alpha = 0;	// stała zmienna kanału aplha

	t = &c->getElapsedTime();	// pobieranie czasu
	if (t->asMilliseconds() > 25 && switcher && alpha <255){	// sprawdzanie czy można zmienić wartość alpha
		alpha += transp;
		if (alpha > 255) alpha = 255;	// sprawdzanie czy nie wyszło się poza zakres
		tekst->setFillColor(Color(255, 255, 255, alpha));
		sp->setColor(Color(255, 255, 255, alpha));
		c->restart();	// restartowanie zegara
	}
	else if (t->asMilliseconds() > 25 && !switcher && alpha >0){
		alpha -= transp;
		if (alpha < 0) alpha = 0;
		tekst->setFillColor(Color(255, 255, 255, alpha));
		sp->setColor(Color(255, 255, 255, alpha));
		c->restart();
	}

	GameWindow::getInstance()->getWindow()->draw(*sp);
	if (alpha == 255){
		tekstDisplayer(dialog);
		tekst->setPosition(textStartPos);
		tekst->setString(dialog);
		GameWindow::getInstance()->getWindow()->draw(*tekst);
	}
	
}	// koniec metody

void TextWriter::setPosition(Vector2f pos){
	tekst->setPosition(pos);
}	// koniec metody

void TextWriter::spSetPostition(Vector2f pos){
	sp->setPosition(pos);
}	// koniec metody

void TextWriter::spSetScale(Vector2f scale){
	sp->setScale(scale);
}	// koniec metody

void TextWriter::setColor(Color c){
	tekst->setFillColor(c);
}	// koniec metody

void TextWriter::areaOnOff(){
	switcher = !switcher;
}	// koniec metody

void TextWriter::tekstDisplayer(String& dialog){
	while (it < dialog.getSize()){
		t = &c->getElapsedTime();

		if (t->asMilliseconds() >= 150){
			tekst->setPosition(Vector2f(tekst->getPosition().x + 10, tekst->getPosition().y));
			tekst->setString(dialog[it++]);
			GameWindow::getInstance()->getWindow()->draw(*tekst);
			GameWindow::getInstance()->getWindow()->display();
			c->restart();
		}
	}	// koniec pętli while
}	// koniec metody