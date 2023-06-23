// testingSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <chrono>
#include "pch.h"
#include <iostream>
#include <mutex>
#include <thread>
#include <memory>
#include <SFML/Graphics.hpp>

std::mutex m;
sf::Sprite sprite;
bool quit = false;

void draw(sf::RenderWindow *window) {
	unsigned i = 0;
	while (!quit) {
		sprite.setPosition((i % 10) * 30, (i / 10) * 30);
		i++;
		if (i > 100) {
			i = 0;
		}
		m.lock();
		std::cout << "Rendering." << std::endl;
		window->setActive(true);
		window->clear();
		window->draw(sprite);
		window->display();
		m.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

int main() {
	sf::Texture texture;
	texture.loadFromFile("Data/kenny.png");
	sprite = sf::Sprite(texture);
	sf::RenderWindow window(sf::VideoMode(400, 200), "test");
	window.setFramerateLimit(60);

	std::thread rendering(draw, &window);
	window.setActive(false);
	
	sf::Event event;
	while (true) {
//		m.lock();
		std::cout << "Waiting for an event" << std::endl;
		bool ok = window.waitEvent(event);
		std::cout << "Event received." << std::endl;
//		m.unlock();
		if (ok) {
			if (event.type == sf::Event::Closed)
				break;
		}
		else
			break;
	}
	quit = true;

	rendering.join();
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
