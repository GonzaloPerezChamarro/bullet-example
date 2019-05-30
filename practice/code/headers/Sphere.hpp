/**
 * @file Sphere.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase que genera una esfera con fisicas
 * @version 0.1
 * @date 2019-05-30
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef SPHERE_HEADER
#define SPHERE_HEADER


#include "Entity.hpp"


namespace example
{
	class Sphere : public Entity
	{

	public:

		/**
		 * @brief Constructor de Sphere
		 * 
		 * @param scene Escena
		 * @param pos Posicion inicial
		 * @param rot Rotacion inicial
		 * @param type Tipo de rigidbody
		 */
		Sphere(Scene * scene, btVector3 pos, btQuaternion rot, Rigidbody::Type type = Rigidbody::Type::STATIC);

		void update(float deltatime) override;

		void reset() override;

	};
}
#endif
