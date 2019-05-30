/**
 * @file Sensor.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase sensor/trigger
 * @version 0.1
 * @date 2019-05-30
 * 
 * @copyright Copyright (c) 2019
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
	private:
		/**
		 * @brief Forma de colision
		 * 
		 */
		std::shared_ptr<btCollisionShape> shape;

		/**
		 * @brief Trigger. btGhostObject de Bullet lib
		 * 
		 */
		std::shared_ptr<btGhostObject> sensor;

		/**
		 * @brief Transform del sensor
		 * 
		 */
		btTransform transform;

	public:
		/**
		 * @brief Constructor de Sensor
		 * 
		 * @param initial_position 
		 * @param initial_rotation 
		 * @param shape 
		 * @param mass 
		 * @param inertia 
		 */
		Sensor(btVector3 & initial_position, btQuaternion & initial_rotation, 
			const std::shared_ptr<btCollisionShape> & shape,
			btScalar mass = 1,
			btVector3 inertia = btVector3(0, 0, 0));

		/**
		 * @brief Destructor de Sensor
		 * 
		 */
		~Sensor() {}

	public:
		/**
		 * @brief Devuelve shape 
		 * 
		 * @return std::shared_ptr<btCollisionShape> 
		 */
		std::shared_ptr<btCollisionShape> get_shape() const { return shape; }

		/**
		 * @brief Devuelve sensor 
		 * 
		 * @return std::shared_ptr<btGhostObject> 
		 */
		std::shared_ptr<btGhostObject> get_sensor() const { return sensor; }

	};
}
#endif
