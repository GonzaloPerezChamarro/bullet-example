/**
 * @file Door.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase puerta
 * @version 0.1
 * @date 2019-05-30
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef DOOR_HEADER
#define DOOR_HEADER


#include "Entity.hpp"

namespace example
{
	class Door :public Entity
	{

	public:
		/**
		 * @brief Constructor de Door
		 * 
		 * @param scene 
		 * @param pos Posicion inicial
		 * @param rot Rotacion inicial
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
