

#ifndef GAME_BULLET_HEADER
#define GAME_BULLET_HEADER

#include "Entity.hpp"
#include <SFML/Graphics.hpp>

namespace example
{
	class Game
	{
	private:
		typedef std::shared_ptr<Entity> sh_Entity;

	private:

		sf::Window window;

		Scene * scene;

	public:

		Game(const char * windows_title, int width, int height);


	public:

		void init();

		void update();

		void render();

		void reset();

		void event_handler();
	};
}

#endif