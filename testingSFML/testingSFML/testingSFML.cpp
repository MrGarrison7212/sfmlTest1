// testingSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <SFML\Graphics.hpp>

int main()
{

	sf::RenderWindow window(sf::VideoMode(300, 300), "SFML Works");

	sf::RectangleShape rectShape(sf::Vector2f(50,50));
	rectShape.setFillColor(sf::Color::White);
	rectShape.setPosition(sf::Vector2f(100, 100));
	rectShape.setOrigin(sf::Vector2f(25,25));


	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
				rectShape.rotate(1.f);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				rectShape.move(sf::Vector2f(0, 1));
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				rectShape.move(sf::Vector2f(0, -1));
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				rectShape.move(sf::Vector2f(-1, 0));
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				rectShape.move(sf::Vector2f(1, 0));
			}
		}

		window.clear();

		window.draw(rectShape);

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
