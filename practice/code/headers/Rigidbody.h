/**
 * @file Rigidbody.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class rigidbody. It has all elements to manage collisions
 * @version 1.0
 * @date 2019-05-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef RIGIDBODY_HEADER
#define RIGIDBODY_HEADER


#include <btBulletDynamicsCommon.h>

#include <memory>

namespace example
{
	class Rigidbody
	{
		/* Collision shape */
		std::shared_ptr<btCollisionShape> shape;

		/* Motion state */
		std::shared_ptr<btDefaultMotionState> state;

		/* Rigidbody */
		std::shared_ptr<btRigidBody> rigidbody;

	public:
		/* Rigidbody type */
		enum Type
		{
			STATIC,
			DYNAMIC,
			KINEMATIC
		};

	public:
		/* Constructor */
		Rigidbody(btVector3 & initial_position, btQuaternion & initial_rotation,
			const std::shared_ptr<btCollisionShape> & shape, Type type = DYNAMIC,
			btScalar mass = 1,
			btVector3 inertia = btVector3(0, 0, 0));

		/* Destructor */
		virtual ~Rigidbody() = default;

	public:
		/* Returns the rigidbody */
		std::shared_ptr<btRigidBody> get_rigidbody() const { return rigidbody; }

		/* Returns the shape*/
		std::shared_ptr<btCollisionShape> get_shape() const { return shape; }
	};
}
#endif
