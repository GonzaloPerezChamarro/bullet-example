/**
 * @file Game.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class of the gameflow
 * @version 1.0
 * @date 2019-05-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef GAME_BULLET_HEADER
#define GAME_BULLET_HEADER

#include "Entity.h"
#include <SFML/Graphics.hpp>

namespace example
{
	class Game
	{
	private:
		typedef std::shared_ptr<Entity> sh_Entity;

	private:
		/* Application window*/
		sf::Window window;

		/* Pointer to game scene */
		Scene * scene;

	public:
		/* Constructor */
		Game(const char * windows_title, int width, int height);

	public:
		/* Initialize the gameflow */
		void init();

		/* Updates the application */
		void update();

		/* Display the game */
		void render();

		/* Reset the game to initial values */
		void reset();

		/* Handle events */
		void event_handler();
	};
}

#endif