/**
 * @file Cube.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase que genera un cubo estandar
 * @version 0.1
 * @date 2019-05-30
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef CUBE_HEADER
#define CUBE_HEADER

#include "Entity.hpp"

namespace example
{
	class Cube : public Entity
	{
	private:

	public:
		/**
		 * @brief Constructor de Cube
		 * 
		 * @param scene Escena
		 * @param pos Posicion inicial
		 * @param rot Rotacion inicial
		 * @param type Tipo de objeto Static/dynamic
		 */
		Cube(Scene * scene, btVector3 pos, btQuaternion rot, Rigidbody::Type type = Rigidbody::Type::STATIC);


		void update(float deltaTime) override;

		void reset() override;
	};
}
#endif
