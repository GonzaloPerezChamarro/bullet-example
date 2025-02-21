

#include "Sensor.h"

namespace example
{
	Sensor::Sensor(btVector3 & initial_position, btQuaternion & initial_rotation, const std::shared_ptr<btCollisionShape>& shape, btScalar mass, btVector3 inertia)
		: shape(shape), sensor(new btGhostObject)
	{
		transform.setIdentity();
		transform.setOrigin(initial_position);
		transform.setRotation(initial_rotation);

		sensor->setCollisionShape(shape.get());
		sensor->setWorldTransform(transform);
		sensor->setCollisionFlags(btCollisionObject::CF_NO_CONTACT_RESPONSE);
	}
}