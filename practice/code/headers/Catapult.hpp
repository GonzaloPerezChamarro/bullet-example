/**
 * @file Catapult.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase de vehiculos catapulta
 * @version 0.1
 * @date 2019-05-30
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef CATAPULT_HEADER
#define CATAPULT_HEADER


#include "Entity.hpp"

namespace example
{
	class Catapult : public Entity
	{
	private:
		/**
		 * @brief Indica si se encuentra disparando
		 * 
		 */
		bool is_firing = false;

		/**
		 * @brief Tiempo entre disparos
		 * 
		 */
		float fire_delay = 2.f;

		/**
		 * @brief Tiempo actual
		 * 
		 */
		float current_time = 0.f;

		/**
		 * @brief Indica si la catapulta debe disparar
		 * 
		 */
		bool have_to_fire = false;

		/**
		 * @brief Fuerza de disparo
		 * 
		 */
		float force = 1000.f;


	public:
		/**
		 * @brief Constructor de Catapult
		 * 
		 * @param scene 
		 * @param pos Posicion inicial
		 * @param rot Rotacion inicial
		 */
		Catapult(Scene * scene, btVector3 pos, btQuaternion rot);

		void update(float deltatime) override;

		void reset() override {}

		void input(float deltaTime) override;

	private:
		/**
		 * @brief Genera un disparo de la catapulta
		 * 
		 */
		void fire();


	
	};
}
#endif
