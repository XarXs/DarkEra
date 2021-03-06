#include "MainMenu.h"

MainMenu::MainMenu(){
	// Tworzenie tablicy możliwych do wyboru opcji
	text = new Text[4];
		
	text[Menu::NewGame].setString(L"Nowa Gra");
	text[Menu::Load].setString(L"Wczytaj");
	text[Menu::Option].setString(L"Opcje");
	text[Menu::Exit].setString(L"Wyjście");		

	// Czy menu jest włączone
	run = true;
	// Dostęp do adresu okna głównego
	okno = MainWindow::getMainWindow()->getWindow();
	targetOption = 0;
	// Ustawianie parametrów tekstu: czcionka, kolor, położenie
	for (int i = 0; i < Menu::End; i++){
		text[i].setFont(*MainWindow::getMainWindow()->getFont());
		if (i == targetOption){
			text[i].setFillColor(Color::Green);
		}else
			text[i].setFillColor(Color::Magenta);
		text[i].setPosition(Vector2f(0.42 * SZER, (WYS * 0.35) + i * 30));
	}

	op = new Options();
}

MainMenu::~MainMenu(){
	delete[] text;
	delete op;
	okno = NULL;
	cout << "destructor MainMenu \n";
}

void MainMenu::draw(){
	okno->clear();
	okno->draw(text[Menu::NewGame]);
	okno->draw(text[Menu::Load]);
	okno->draw(text[Menu::Option]);
	okno->draw(text[Menu::Exit]);
	okno->display();
}

void MainMenu::runMenu(){
	MainWindow::getMainWindow()->playMusic();
	while (okno->isOpen()&& run){

		Event events;
		while (okno->pollEvent(events)){

			switch (events.type){
			case Event::Closed:
				okno->close();
				break;
			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Down)){
					this->moveDown();
				}
				else if (Keyboard::isKeyPressed(Keyboard::Up)){
					this->moveUp();
				}
				else if (Keyboard::isKeyPressed(Keyboard::Return)){
					this->enter();
				}
				break;
			}// koniec switcha
		}// koniec pętli event

		this->draw();
	} // główna pętla
}

void MainMenu::moveDown(){
	if (targetOption >= 0 && targetOption < Menu::Exit){
		text[targetOption++].setFillColor(Color::Magenta);
		text[targetOption].setFillColor(Color::Green);
	}
}

void MainMenu::moveUp(){
	if (targetOption > 0 && targetOption < Menu::End){
		text[targetOption--].setFillColor(Color::Magenta);
		text[targetOption].setFillColor(Color::Green);
	}
}

void MainMenu::enter(){
	if (targetOption == Menu::Exit){
		MainWindow* m = MainWindow::getMainWindow();
		m->stopMusic();
		okno->close();
	}
	if (targetOption == Menu::Option){
		op->run();
	}
	if (targetOption == Menu::NewGame){
		run = false;
	}
}