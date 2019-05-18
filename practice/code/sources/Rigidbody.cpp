

#include "Rigidbody.hpp"


namespace example
{
	Rigidbody::Rigidbody(btVector3 & initial_position, btQuaternion & initial_rotation, const std::shared_ptr<btCollisionShape>& shape,Type type, btScalar mass, btVector3 inertia)
		:shape(shape)
	{
		shape->calculateLocalInertia(mass, inertia);

		if (type == STATIC)
		{
			btRigidBody::btRigidBodyConstructionInfo info(0, state.get(), shape.get());
			rigidbody.reset(new btRigidBody(info));
		}
		else if (type == DYNAMIC)
		{
			btRigidBody::btRigidBodyConstructionInfo info(mass, state.get(), shape.get(), inertia);
			rigidbody.reset(new btRigidBody(info));
			rigidbody->setActivationState(DISABLE_DEACTIVATION);
		}
	}
}