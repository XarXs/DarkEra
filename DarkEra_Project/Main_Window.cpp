#include "Main_Window.h"

MainWindow::MainWindow(){
	window = new RenderWindow(VideoMode(640, 480), "DarkEra-Project", Style::Close);
	window->setFramerateLimit(30);
}

MainWindow::~MainWindow(){
	cout << "destructor MainWindow\n";
	delete window;
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