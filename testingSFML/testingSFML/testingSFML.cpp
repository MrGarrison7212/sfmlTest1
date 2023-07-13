// testingSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <mutex>
#include <string>
#include <thread>
#include <queue>

#include <SFML/Graphics.hpp>

class Application
{
	sf::RenderWindow m_window;
	std::queue<sf::Event> m_eventQueue;
	std::mutex m_sharedAccess;

	void renderGame()
	{
		m_window.setActive(true);

		sf::RectangleShape rectangle(sf::Vector2f(200, 200));
		rectangle.setFillColor(sf::Color::Red);
		unsigned i = 0;
//		rectangle.setPosition(sf::Vector2f(200.f, 200.f));

		sf::Clock clock;
		sf::Time accumulator = sf::Time::Zero;

		while (m_window.isOpen())
		{
			{
				std::unique_lock<std::mutex> lock(m_sharedAccess);
				while (!m_eventQueue.empty())
				{
					sf::Event event;
					event = m_eventQueue.back();
					m_eventQueue.pop();

					if (event.type == sf::Event::Closed)
					{
						m_window.close();
					}
				}
			}

			rectangle.setPosition((i % 10) * 30, (i / 10) * 30);
			i++;
			if (i > 100) {
				i = 0;
			}

			if (rectangle.getFillColor() == sf::Color::Red)
			{
				rectangle.setFillColor(sf::Color::Blue);
			}
			else
			{
				rectangle.setFillColor(sf::Color::Red);
			}

			sf::Time frameTime = clock.restart();
			accumulator += frameTime;

			if (accumulator >= sf::seconds(1.f))
			{
//				m_window.setTitle(std::to_string(1.f / frameTime.asSeconds()));
				accumulator = sf::Time::Zero;
			}

			m_window.clear();
			m_window.draw(rectangle);
			m_window.display();
		}
	}

public:
	Application() : m_window(sf::VideoMode(300, 300), "Wait Event")
	{
		m_window.setFramerateLimit(144);
	}

	void run()
	{
		m_window.setActive(false);

		std::thread renderThread(&Application::renderGame, this);

		sf::Event event;
		while (m_window.waitEvent(event))
		{

			{
				std::unique_lock<std::mutex> lock(m_sharedAccess);
				m_eventQueue.push(event);
			}

			if (event.type == sf::Event::Closed)
			{
				break;
			}
		}

		renderThread.join();
	}
};

int main()
{
	Application app;
	app.run();
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
