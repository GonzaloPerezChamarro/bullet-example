#include "Door.hpp"

void example::Door::update(float deltatime)
{
	Entity::update(deltatime);

	if (have_to_open)
	{
		models["door"].body->get_rigidbody()->setLinearVelocity(btVector3(0,1,0) * speed);

		if (!near_equals(models["door"].body->get_rigidbody()->getWorldTransform().getOrigin(), initial_position + btVector3(0, 3, 0), 0.01f))
		{
			models["door"].body->get_rigidbody()->getWorldTransform().setOrigin(initial_position + btVector3(0, 3,0));
			have_to_open = false;
		}

	}
}

void example::Door::open()
{
	have_to_open = true;
}
