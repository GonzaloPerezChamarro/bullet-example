

#ifndef WORLD_BULLET_HEADER
#define WORLD_BULLET_HEADER

#include <btBulletDynamicsCommon.h>
#include <memory>

#include "Rigidbody.hpp"
#include "Sensor.hpp"

namespace example
{
	class World
	{
	private:
		std::shared_ptr<btDiscreteDynamicsWorld> physic_world;

		btDefaultCollisionConfiguration collision_configuration;
		btCollisionDispatcher collision_dispatcher;
		btDbvtBroadphase overlapping_pair_cache;
		btSequentialImpulseConstraintSolver constraint_solver;

	public:

		World(const btVector3 & gravity = btVector3(0, -10, 0));

		~World()
		{
			physic_world.reset();
		}

	public:

		void update(float deltaTime);

	public:
		
		void add_rigidbody(const std::shared_ptr<Rigidbody> & rigidbody);

		void add_sensor(const std::shared_ptr<Sensor> & sensor);

		void add_joint(const std::shared_ptr<btTypedConstraint> & joint);

		void set_gravity(btVector3 & new_gravity) { physic_world->setGravity(new_gravity); }
	};
}

#endif