#include "Option.h"

Options::Options(){
	okno = MainWindow::getMainWindow()->getWindow();
	text.setFont(*MainWindow::getMainWindow()->getFont());
}

void Options::run(){
	while (okno->isOpen()){
		Event events;
		while (okno->pollEvent(events)){

			switch (events.type){
			case Event::Closed:
				okno->close();
				break;
			}// koniec switcha
		}// koniec pętli event


	}//koniec głównej pętli
	this->render();
}

void Options::render(){
	okno->clear();

	text.setString("<");
	text.setPosition(Vector2f(0.42 * SZER, (WYS * 0.35)));
	okno->draw(text);

	pom = to_string(MainWindow::getMainWindow()->getValue());
	text.setString(pom);
	text.setPosition(Vector2f(0.42 * SZER, (WYS * 0.35)+10));
	okno->draw(text);

	text.setString(">");
	text.setPosition(Vector2f(0.42 * SZER, (WYS * 0.35)+20));
	okno->draw(text);

	okno->display();
}