#include "Main_Window.h"

MainWindow::MainWindow(){
	window = new RenderWindow(VideoMode(SZER, WYS), "DarkEra-Project", Style::Close);
	window->setFramerateLimit(30);

	if (!font.loadFromFile("Fonts/NewRocker-Regular.otf")){
		cout << "Error: font not found\n";
		exit(0);
	}
	music = new Music();
	if (!music->openFromFile("Music/Soundtrack_homemade_02.wav")){
		cout << "ERRO: Music not found\n";
		exit(0);
	}

	music->setLoop(true);
}

MainWindow::~MainWindow(){
	cout << "destructor MainWindow\n";
	delete window;
	music->stop();
	delete music;
	delete instance;
}

MainWindow* MainWindow::instance = 0;

MainWindow* MainWindow::getMainWindow(){
	if (instance == 0)
		instance = new MainWindow();
	return instance;
}

RenderWindow* MainWindow::getWindow(){
	return window;
}

void MainWindow::setMusic(string source){
	if (!music->openFromFile(source)){
		cout << "ERROR: Music not found\n";
		exit(0);
	}
}

void MainWindow::playMusic(){
	music->play();
}

void MainWindow::stopMusic(){
	music->stop();
}

void MainWindow::setValue(int value){
	music->setVolume(value);
}

int MainWindow::getValue(){
	return music->getVolume();
}

void MainWindow::setFont(string source){
	if (!font.loadFromFile(source)){
		cout << "Error: font not found\n";
		exit(0);
	}
}

Font* MainWindow::getFont(){
	return &font;
}