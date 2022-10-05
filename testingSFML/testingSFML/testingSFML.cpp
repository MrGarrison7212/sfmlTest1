// testingSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

int main()
{

	sf::RenderWindow window(sf::VideoMode(300, 300), "SFML Works");

	sf::RectangleShape rectShape(sf::Vector2f(50,50));
	rectShape.setFillColor(sf::Color::White);
	rectShape.setPosition(sf::Vector2f(100, 100));
	rectShape.setOrigin(sf::Vector2f(25,25));

	sf::Music exampleMusic;

	if (exampleMusic.openFromFile("Data/kennywo.wav") == false) {
		std::cout << "Loading failed" << std::endl;
	}

	exampleMusic.play();

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();

		window.draw(rectShape);

		window.display();
	}

	return 0;
}


