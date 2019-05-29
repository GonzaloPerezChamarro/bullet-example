

#include "Rigidbody.hpp"


namespace example
{
	Rigidbody::Rigidbody(btVector3 & initial_position, btQuaternion & initial_rotation, const std::shared_ptr<btCollisionShape>& shape,Type type, btScalar mass, btVector3 inertia)
		:shape(shape)
	{
		
		shape->calculateLocalInertia(mass, inertia);

		btTransform tr;

		tr.setIdentity();
		tr.setOrigin(initial_position);
		tr.setRotation(initial_rotation);

		state.reset(new btDefaultMotionState(tr));

		if (type == STATIC)
		{
			btRigidBody::btRigidBodyConstructionInfo info(0, state.get(), shape.get());
			rigidbody.reset(new btRigidBody(info));
		}
		else if(type == DYNAMIC)
		{
			btRigidBody::btRigidBodyConstructionInfo info(mass, state.get(), shape.get(), inertia);
			rigidbody.reset(new btRigidBody(info));
			rigidbody->setActivationState(DISABLE_DEACTIVATION);
		}
		else
		{
			btRigidBody::btRigidBodyConstructionInfo info(0, state.get(), shape.get());
			rigidbody.reset(new btRigidBody(info));

			rigidbody->setCollisionFlags(btCollisionObject::CF_KINEMATIC_OBJECT);

;
		}
	}
}