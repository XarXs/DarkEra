#include "Biblioteki.h"
#include <cmath>
int main()
{
	MainWindow *okno = MainWindow::getMainWindow();
	sf::Clock stoper;
	while (okno->getWindow()->isOpen())
	{
		Event event;
		while (okno->getWindow()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				okno->getWindow()->close();

		} //while
		okno->getWindow()->clear();

		sf::CircleShape ksztalt(std::sin(stoper.getElapsedTime().asSeconds()) * okno->getWindow()->getSize().y / 8 + okno->getWindow()->getSize().y / 4);
		ksztalt.setOrigin(sf::Vector2f(ksztalt.getRadius(), ksztalt.getRadius()));
		ksztalt.setPosition(okno->getWindow()->getSize().x / 2.0f, okno->getWindow()->getSize().y / 2.0f);
		ksztalt.setFillColor(sf::Color::Yellow);
		okno->getWindow()->draw(ksztalt);

		okno->getWindow()->display();
	} //while
	return 0;
}