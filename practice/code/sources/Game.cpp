

#include "Game.h"

namespace example
{
	Game::Game(const char * windows_title, int width, int height)
		:window(sf::VideoMode(width, height), windows_title,
			sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings(24, 0, 0, 3, 2, sf::ContextSettings::Core)),
			scene(new Scene(window.getSize().x, window.getSize().y, 10.f))
	{
		// Init openGl
		if (!glt::initialize_opengl_extensions())
		{
			exit(-1);
		}

		// Create the scene
		scene->create_scene();

		// Create the window
		glViewport(0, 0, width, height);
		
		window.setFramerateLimit(60);
		window.setVerticalSyncEnabled(true);

		glClearColor(0.2f, 0.2f, 0.3f, 1.f);
	}

	void Game::init()
	{
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

		// Gameflow
		do
		{
			time = timer.getElapsedTime();
			
			scene->update(deltaTime.asSeconds());

			
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			render();
			window.display();

			event_handler();
			
			deltaTime = time - last_time;
			last_time = time;

		} 
		while (window.isOpen());
	}

	void Game::render()
	{
		scene->render();

	}

	void Game::reset()
	{
		
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
}