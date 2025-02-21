/**
 * @file Scene.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class of a game scene
 * @version 1.0
 * @date 2019-05-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef SCENE_BULLET_HEADER
#define SCENE_BULLET_HEADER


#include <string>
#include <map>

#include <SFML/Window.hpp>

#include <Render_Node.hpp>
#include <Light.hpp>

#include "World.h"

using namespace std;

namespace example
{
	class Entity;
	class Game;
	class Scene
	{
	private:
		/**
		 * @brief Pinta los elementos de pantalla
		 * 
		 */
		std::shared_ptr<glt::Render_Node> renderer;

		/**
		 * @brief Camara princial de la escena
		 * 
		 */
		std::shared_ptr<glt::Camera> camera;

		/**
		 * @brief Luz principal de la escena
		 * 
		 */
		std::shared_ptr<glt::Light> light;

	private:
		typedef shared_ptr<Entity> sh_Entity;

		/**
		 * @brief Mapa de entidades de la escena
		 * 
		 */
		map<string, sh_Entity> entities_map;

		/**
		 * @brief Ancho de la pantalla
		 * 
		 */
		int width;

		/**
		 * @brief Alto de la pantalla
		 * 
		 */
		int height;

		/**
		 * @brief Gravedad
		 * 
		 */
		float gravity;

		/**
		 * @brief Indica si tiene que resetear la escena
		 * 
		 */
		bool have_to_reset;


		/**
		 * @brief Puntero al flujo de juego
		 * 
		 */
		Game * game;

		/**
		 * @brief Mundo de fisicas
		 * 
		 */
		std::shared_ptr<World> world;

	public:
		/**
		 * @brief Constructor de Scene
		 * 
		 * @param width Ancho de la pantalla
		 * @param height Alto de la pantalla
		 * @param gravity Gravedad
		 */
		Scene(int width, int height, float gravity);

		/**
		 * @brief Destructor de Scene
		 * 
		 */
		virtual ~Scene();

	public:
		/**
		 * @brief Actualiza el estado de la escena
		 * 
		 * @param deltaTime 
		 */
		void update(float deltaTime);

		/**
		 * @brief Renderiza los elementos de la escena
		 * 
		 */
		void render();

	public:
		/**
		 * @brief Crea la escena
		 * 
		 */
		void create_scene();

		/**
		 * @brief Devuelve world 
		 * 
		 * @return World& 
		 */
		World & get_world() { return *world; }

		/**
		 * @brief Devuelve width 
		 * 
		 * @return int 
		 */
		int get_width() { return width; }

		/**
		 * @brief Devuelve height 
		 * 
		 * @return int 
		 */
		int get_height() { return height; }

		/**
		 * @brief Devuelve gravity 
		 * 
		 * @return float 
		 */
		float get_gravity() const { return gravity; }

		/**
		 * @brief Modifica el valor de have to reset 
		 * 
		 * @param b 
		 */
		void set_have_to_reset(bool b) { have_to_reset = b; }

		/**
		 * @brief Añade una nueva entidad a la escena
		 * 
		 * @param name Nombre de la entidad
		 * @param entity Entidad
		 */
		void add_entity(const std::string name, const sh_Entity & entity);

		/**
		 * @brief Devuelve una entidad por su nombre
		 * 
		 * @param name 
		 * @return Entity* 
		 */
		Entity * get_entity_by_name(const std::string & name);

		/**
		 * @brief Devuelve renderer 
		 * 
		 * @return std::shared_ptr<glt::Render_Node> 
		 */
		std::shared_ptr<glt::Render_Node> get_renderer() const { return renderer; }

	private:
		/**
		 * @brief Resetea la escena
		 * 
		 */
		void reset();

		/**
		 * @brief Gestion de eventos
		 * 
		 * @param deltaTime 
		 */
		void input(float deltaTime);

	};

}

#endif
