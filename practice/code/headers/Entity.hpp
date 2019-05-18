#ifndef ENTITY_BULLET_HEADER
#define ENTITY_BULLET_HEADER


#include <map>
#include <string>

#include "Scene.hpp"
#include "Rigidbody.hpp"

#include <btBulletDynamicsCommon.h>


using namespace std;

namespace example
{
	class Entity
	{
	protected:
		Scene * scene;

		btVector3 initial_position;
		btTransform transform;

		std::map<std::string, std::shared_ptr< Rigidbody>> bodies;
		std::map<std::string, std::shared_ptr<Sensor>> sensors;
		std::map<std::string, std::shared_ptr<btHingeConstraint>> joints;


	public:
		Entity(Scene * scene, btVector3 pos)
			:scene(scene), initial_position(pos)
		{
			transform.setOrigin(initial_position);
		}

		virtual ~Entity() {}

	public:
		virtual void update(float deltatime) = 0;
		virtual void render(sf::RenderWindow & renderer) = 0;

		virtual void reset() = 0;

	public:

		std::shared_ptr<Rigidbody> get_rigidbody(const std::string & name)
		{
			return bodies[name];
		}

		const btVector3 & get_current_position() const;

		Scene * get_scene() const { return scene; }
	};
}

#endif
