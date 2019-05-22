

#ifndef SENSOR_HEADER
#define SENSOR_HEADER

#include <memory>
#include <BulletCollision/CollisionDispatch/btGhostObject.h>

namespace example
{
	class Sensor
	{
	private:
		std::shared_ptr<btCollisionShape> shape;

		std::shared_ptr<btGhostObject> sensor;

		btTransform transform;

	public:

		Sensor(btVector3 & initial_position, btQuaternion & initial_rotation, 
			const std::shared_ptr<btCollisionShape> & shape,
			btScalar mass = 1,
			btVector3 inertia = btVector3(0, 0, 0));

		~Sensor() {}

	public:

		std::shared_ptr<btCollisionShape> get_shape() const { return shape; }

		std::shared_ptr<btGhostObject> get_sensor() const { return sensor; }

	};
}
#endif
