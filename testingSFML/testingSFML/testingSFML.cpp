// testingSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <SFML\Graphics.hpp>

int main()
{

	sf::RenderWindow window(sf::VideoMode(300, 300), "SFML Works");

	sf::RectangleShape shape(sf::Vector2f(150,150));

	shape.setFillColor(sf::Color::Blue);

	bool jump = false;

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {

//			if (event.type == sf::Event::Closed) {
//				window.close();
//			}

			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Space)
					jump = true;
				break;
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Space)
					jump = true;
				break;
			}

		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
