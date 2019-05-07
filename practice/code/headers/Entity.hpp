#ifndef ENTITY_BULLET_HEADER
#define ENTITY_BULLET_HEADER


#include <map>
#include <string>

#include "Scene.hpp"

using namespace std;



namespace example
{
	class Entity
	{
	protected:

		map<string, shared_ptr<btRigidBody>> rigidbodies;
		map<string, shared_ptr<btHingeConstraint>> joints;

		

		Scene * scene;

		btVector3 initial_position;
		btTransform transform;

		sf::Color color;

	public:
		Entity(Scene * scene, btVector3 pos);

		virtual ~Entity();

	public:
		virtual void update(float deltatime) = 0;
		virtual void render(sf::RenderWindow & renderer) = 0;

	public:
		Scene * get_scene() const { return scene; }

		virtual void collision_enter(Entity * ) = 0;
		virtual void collision_exit(Entity * ) = 0;

		virtual void reset() {}

		const btVector3 & get_current_position() const;
	};
}

#endif
