/**
 * @file Rigidbody.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase rigidbody. Recoge todos os elementos necesarios para la colision
 * @version 0.1
 * @date 2019-05-30
 * 
 * @copyright Copyright (c) 2019
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
		/**
		 * @brief Forma de colision
		 * 
		 */
		std::shared_ptr<btCollisionShape> shape;

		/**
		 * @brief Estado
		 * 
		 */
		std::shared_ptr<btDefaultMotionState> state;

		/**
		 * @brief Cuerpo rigido
		 * 
		 */
		std::shared_ptr<btRigidBody> rigidbody;

	public:
		/**
		 * @brief Tipo de rigidbody
		 * 
		 */
		enum Type
		{
			STATIC,
			DYNAMIC,
			KINEMATIC
		};

	public:
		/**
		 * @brief Constructor de Rigidbody
		 * 
		 * @param initial_position 
		 * @param initial_rotation 
		 * @param shape 
		 * @param type 
		 * @param mass 
		 * @param inertia 
		 */
		Rigidbody(btVector3 & initial_position, btQuaternion & initial_rotation,
			const std::shared_ptr<btCollisionShape> & shape, Type type = DYNAMIC,
			btScalar mass = 1,
			btVector3 inertia = btVector3(0, 0, 0));

		/**
		 * @brief Destructor de Rigidbody
		 * 
		 */
		virtual ~Rigidbody() = default;

	public:
		/**
		 * @brief Devuelve rigidbody 
		 * 
		 * @return std::shared_ptr<btRigidBody> 
		 */
		std::shared_ptr<btRigidBody> get_rigidbody() const { return rigidbody; }

		/**
		 * @brief Devuelve shape 
		 * 
		 * @return std::shared_ptr<btCollisionShape> 
		 */
		std::shared_ptr<btCollisionShape> get_shape() const { return shape; }

	};
}
#endif
