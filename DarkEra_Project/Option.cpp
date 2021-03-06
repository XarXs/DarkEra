#include "Option.h"

Options::Options(){
	okno = MainWindow::getMainWindow()->getWindow();
	text = new Text[3];
	for (int i = 0; i < 3; i++)	text[i].setFont(*MainWindow::getMainWindow()->getFont());

	text[0].setString("<");
	text[0].setPosition(Vector2f(0.42 * SZER, (WYS * 0.35)));


	text[1].setPosition(Vector2f(0.42 * SZER + 15, (WYS * 0.35)));

	text[2].setString(">");
	text[2].setPosition(Vector2f(0.42 * SZER + 65, (WYS * 0.35)));

	volume = MainWindow::getMainWindow()->getValue();
	on = true;
}

Options::~Options(){
	delete[] text;
	okno = NULL;
	cout << "destructor Options\n";
}

void Options::run(){
	while (okno->isOpen() && on){
		Event events;
		while (okno->pollEvent(events)){

			switch (events.type){
			case Event::Closed:
				okno->close();
				break;
			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Left)) this->left();
				else if (Keyboard::isKeyPressed(Keyboard::Right)) this->right();
				else if (Keyboard::isKeyPressed(Keyboard::Escape)) on = false;
				break;
			}// koniec switcha
		}// koniec pętli event

		this->render();
	}//koniec głównej pętli
	on = true;
}

void Options::left(){
	if (volume>0)
		MainWindow::getMainWindow()->setValue(--volume);
}

void Options::right(){
	if (volume<100)
		MainWindow::getMainWindow()->setValue(volume++);
}

void Options::render(){
	okno->clear();

	pom = to_string(volume);
	text[1].setString(pom);
	for (int i = 0; i < 3; i++)	okno->draw(text[i]);

	okno->display();
}