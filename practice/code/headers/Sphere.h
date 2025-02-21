/**
 * @file Sphere.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class that represents a sphere 
 * @version 1.0
 * @date 2019-05-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef SPHERE_HEADER
#define SPHERE_HEADER


#include "Entity.h"
namespace example
{
	class Sphere : public Entity
	{

	public:

		/**
		 * @brief Constructor
		 * @param scene Pointer to game scene
		 * @param pos Initial position
		 * @param rot Initial rotation
		 * @param type Rigidbody type
		 */
		Sphere(Scene * scene, btVector3 pos, btQuaternion rot, Rigidbody::Type type = Rigidbody::Type::STATIC);

		void update(float deltatime) override;
		void reset() override;
	};
}
#endif
