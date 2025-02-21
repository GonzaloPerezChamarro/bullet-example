/**
 * @file Sensor.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class sensor/trigger
 * @version 1.0
 * @date 2019-05-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef SENSOR_HEADER
#define SENSOR_HEADER

#include <memory>
#include <BulletCollision/CollisionDispatch/btGhostObject.h>

namespace example
{
	class Sensor
	{
	public:
		/* Constructor */
		Sensor(btVector3 & initial_position, btQuaternion & initial_rotation, 
			const std::shared_ptr<btCollisionShape> & shape,
			btScalar mass = 1,
			btVector3 inertia = btVector3(0, 0, 0));

		/* Destructor */
		~Sensor() {}

	public:
		/* Returns the collision shape */
		std::shared_ptr<btCollisionShape> get_shape() const { return shape; }

		/* Returns the sensor */
		std::shared_ptr<btGhostObject> get_sensor() const { return sensor; }

	private:
		/* Collision shape */
		std::shared_ptr<btCollisionShape> shape;

		/* Trigger. btGhostObject of Bullet lib */
		std::shared_ptr<btGhostObject> sensor;

		/* Transform */
		btTransform transform;
	};
}
#endif
