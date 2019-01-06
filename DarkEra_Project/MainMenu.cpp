#include "MainMenu.h"

MainMenu::MainMenu(){
	font.loadFromFile("Fonts/NewRocker-Regular.otf");
	text = new Text[4];
	
	
	text[Menu::NewGame].setString(L"Nowa Gra");
	text[Menu::Load].setString(L"Wczytaj");
	text[Menu::Option].setString(L"Opcje");
	text[Menu::Exit].setString(L"Wyjście");		

	run = true;

	okno = MainWindow::getMainWindow()->getWindow();
	for (int i = 0; i < Menu::End; i++){
		text[i].setFont(font);
		text[i].setFillColor(Color::Magenta);
		text[i].setPosition(Vector2f(25, i * 30));
	}
}

MainMenu::~MainMenu(){
	delete[] text;
	cout << "destructor MainMenu \n";
}

void MainMenu::draw(){
	
	okno->draw(text[Menu::NewGame]);
	okno->draw(text[Menu::Load]);
	okno->draw(text[Menu::Option]);
	okno->draw(text[Menu::Exit]);
}