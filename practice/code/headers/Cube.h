/**
 * @file Cube.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class that represent a base cube
 * @version 1.0
 * @date 2019-05-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef CUBE_HEADER
#define CUBE_HEADER

#include "Entity.h"

namespace example
{
	class Cube : public Entity
	{
	public:
		/**
		 * @brief Constructor
		 * @param scene Pointer to game scene
		 * @param pos Initial position
		 * @param rot Initial rotation
		 * @param type Object type -> Static/dynamic
		 */
		Cube(Scene * scene, btVector3 pos, btQuaternion rot, Rigidbody::Type type = Rigidbody::Type::STATIC);

		void update(float deltaTime) override;
		void reset() override;
	};
}
#endif
