// testingSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <chrono>
#include "pch.h"
#include <iostream>
#include <mutex>
#include <thread>
#include <memory>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(300, 300), "SFML Works");
	window.setFramerateLimit(144);

	sf::RectangleShape rectangle(sf::Vector2f(200, 200));
	rectangle.setFillColor(sf::Color::Red);

	while (window.isOpen())
	{

		window.clear();
		window.draw(rectangle);
		window.display();

		auto event = sf::Event{};

		if (window.waitEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed) {
				if (rectangle.getFillColor() == sf::Color::Red)
				{
					rectangle.setFillColor(sf::Color::Blue);
				}
				else
				{
					rectangle.setFillColor(sf::Color::Red);
				}
			}

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
	}
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
