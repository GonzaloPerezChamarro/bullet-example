

#ifndef SCENE_BULLET_HEADER
#define SCENE_BULLET_HEADER


#include <string>
#include <map>

#include <SFML/Graphics.hpp>
#include <btBulletDynamicsCommon.h>

using namespace std;

namespace example
{
	class Entity;
	class Game;
	class Scene
	{
	private:
		typedef shared_ptr<Entity> sh_Entity;

		map<string, sh_Entity> entities_map;

		int width;

		int height;

		float gravity;

		bool have_to_reset;

		Game * game;

		btDefaultCollisionConfiguration collisionConfiguration;
		btCollisionDispatcher collisionDispatcher;
		btDbvtBroadphase overlappingPairCache;
		btSequentialImpulseConstraintSolver constraintSolver;

		btDiscreteDynamicsWorld world;

	public:

		Scene(int width, int height, float gravity);
		virtual ~Scene();

	public:
		void update(float deltaTime);

		void render(sf::RenderWindow & renderer);

	public:

		btDiscreteDynamicsWorld & get_world() { return world; }

		int get_width() { return width; }

		int get_height() { return height; }

		float get_gravity() const { return gravity; }

		void set_have_to_reset(bool b) { have_to_reset = b; }

		void add_entity(const std::string name, const sh_Entity & entity);

		Entity * get_entity_by_name(const std::string & name);

	private:
		void reset();

	};



}

#endif
