
#include "World.h"

namespace example
{
	World::World(const btVector3 & gravity)
		:collision_dispatcher(&collision_configuration)
	{
		physic_world.reset(new btDiscreteDynamicsWorld(&collision_dispatcher,
														&overlapping_pair_cache,
														&constraint_solver,
														&collision_configuration));

		physic_world->setGravity(gravity);
	}

	void World::update(float deltaTime)
	{
		physic_world->stepSimulation(deltaTime);
	}

	void World::add_rigidbody(const std::shared_ptr<Rigidbody>& rigidbody)
	{
		physic_world->addRigidBody(rigidbody->get_rigidbody().get());
	}

	void World::add_sensor(const std::shared_ptr<Sensor>& sensor)
	{
		physic_world->addCollisionObject(sensor->get_sensor().get());
		physic_world->getBroadphase()->getOverlappingPairCache()->setInternalGhostPairCallback(new btGhostPairCallback());
	}

	void World::add_joint(const std::shared_ptr<btTypedConstraint>& joint)
	{
		physic_world->addConstraint(joint.get());
	}
}