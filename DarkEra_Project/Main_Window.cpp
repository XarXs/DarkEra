#include "Main_Window.h"

MainWindow::MainWindow(){
	window = new RenderWindow(VideoMode(SZER, WYS), "DarkEra-Project", Style::Close);
	window->setFramerateLimit(30);

	if (!font.loadFromFile("Fonts/NewRocker-Regular.otf")){
		string e = "Error: font not found\n";
		throw(e);
	}
	music = new Music();
	if (!music->openFromFile("Music/Soundtrack_homemade_02.wav")){
		string e = "ERRO: Music not found\n";
		throw(e);
	}

	music->setLoop(true);

	camera = new Camera();
}

MainWindow::~MainWindow(){
	cout << "destructor MainWindow\n";
	music->stop();
	delete music;
	delete camera;
	delete window;
	instance = NULL;
	cout << "end of MainWindow destructor\n";
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
		string e = "ERROR: Music not found\n";
		throw(e);
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
		string e = "Error: font not found\n";
		throw(e);
	}
}

Font* MainWindow::getFont(){
	return &font;
}

Camera* MainWindow::getCamera(){
	return camera;
}