

#include "Game.hpp"

namespace example
{
	Game::Game(const char * windows_title, int width, int height)
		:window(sf::VideoMode(width, height), windows_title,
			sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings(32)),
			scene(new Scene(window.getSize().x, window.getSize().y, 10.f))
	{
		
		window.setFramerateLimit(60);

	}
	void Game::init()
	{
		generate_world();
		update();
	}

	void Game::update()
	{
		constexpr unsigned fps = 60;
		sf::Time timeUpdate = sf::seconds(1.0f / float(fps));
		sf::Clock timer;
		auto last_time = sf::Time::Zero;
		auto time = timer.getElapsedTime();
		auto deltaTime = time - last_time;

		do
		{
			time = timer.getElapsedTime();
			
			scene->update(deltaTime.asSeconds());

			
			window.clear();
			render();
			window.display();

			event_handler();
			
			deltaTime = time - last_time;
			last_time = time;

		} while (window.isOpen());
	}
	void Game::render()
	{
		scene->render(window);

	}
	void Game::reset()
	{
		//Reseteando
	}
	void Game::event_handler()
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}
	}
	void Game::generate_world()
	{
		//Generando......
	}
}