/**
 * @file Game.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase de flujo de juego
 * @version 0.1
 * @date 2019-05-30
 * 
 * @copyright Copyright (c) 2019
 * 
 */

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
		/**
		 * @brief Ventana de aplicacion
		 * 
		 */
		sf::Window window;
		/**
		 * @brief Puntero a la escena
		 * 
		 */
		Scene * scene;

	public:
		/**
		 * @brief Constructor de Game
		 * 
		 * @param windows_title Titulo de la ventana
		 * @param width Ancho de la ventana
		 * @param height Alto de la ventana
		 */
		Game(const char * windows_title, int width, int height);


	public:
		/**
		 * @brief Inicializa el flujo de juego
		 * 
		 */
		void init();

		/**
		 * @brief Actualiza la aplicacion
		 * 
		 */
		void update();

		/**
		 * @brief Pinta en pantalla
		 * 
		 */
		void render();

		/**
		 * @brief Resetea los valores iniciales
		 * 
		 */
		void reset();

		/**
		 * @brief Gestion de eventos
		 * 
		 */
		void event_handler();
	};
}

#endif