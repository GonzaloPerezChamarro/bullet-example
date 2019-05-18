
#ifndef RIGIDBODY_HEADER
#define RIGIDBODY_HEADER


#include <btBulletDynamicsCommon.h>

#include <memory>

namespace example
{
	class Rigidbody
	{
		std::shared_ptr<btCollisionShape> shape;
		std::shared_ptr<btDefaultMotionState> state;
		std::shared_ptr<btRigidBody> rigidbody;

	public:

		enum Type
		{
			STATIC,
			DYNAMIC
		};

	public:

		Rigidbody(btVector3 & initial_position, btQuaternion & initial_rotation,
			const std::shared_ptr<btCollisionShape> & shape, Type type = DYNAMIC,
			btScalar mass = 1,
			btVector3 inertia = btVector3(0, 0, 0));

		virtual ~Rigidbody() = default;

	public:

		std::shared_ptr<btRigidBody> get_rigidbody() const { return rigidbody; }
		std::shared_ptr<btCollisionShape> get_shape() const { return shape; }

	};
}
#endif
