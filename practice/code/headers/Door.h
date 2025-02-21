/**
 * @file Door.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class that represents a door
 * @version 1.0
 * @date 2019-05-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef DOOR_HEADER
#define DOOR_HEADER


#include "Entity.h"

namespace example
{
	class Door :public Entity
	{
	public:
		/**
		 * @brief Constructor
		 * @param scene Pointer to game scene
		 * @param pos Initial position
		 * @param rot Initial rotation
		 */
		Door(Scene * scene, btVector3 pos, btQuaternion rot)
			:Entity(scene, pos, rot)
		{
			std::shared_ptr<Rigidbody> body(new Rigidbody(pos, rot, std::shared_ptr<btBoxShape>(new btBoxShape(btVector3(0.1f, 1.0f, 0.3f))), Rigidbody::Type::STATIC));
			add_model("door", body, "../../assets/door.obj");
		}

		void reset() override {}
	};
}
#endif
