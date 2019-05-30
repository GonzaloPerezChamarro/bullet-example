/**
 * @file Platform.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase plataforma. Cuerpo kinematico que se mueve cuando el jugador se coloca sobre el
 * @version 0.1
 * @date 2019-05-30
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef PLATFORM_HEADER
#define PLATFORM_HEADER


#include "Entity.hpp"


namespace example
{
	class Platform :public Entity
	{
	private:
		/**
		 * @brief Posicion objetiva
		 * 
		 */
		btVector3 target;

		/**
		 * @brief Direccion
		 * 
		 */
		btVector3 direction;

		/**
		 * @brief Velocidad de movimiento
		 * 
		 */
		float speed = .4f;

		/**
		 * @brief Tiempo de espera cuando el jugador se posiciona encima
		 * 
		 */
		float delay = 2.f;

		/**
		 * @brief Tiempo actual
		 * 
		 */
		float current_time;

		/**
		 * @brief Indica si se encuentra parada la plataforma
		 * 
		 */
		bool stopped;

		/**
		 * @brief Indica si debe moverse
		 * 
		 */
		bool have_to_move;

		/**
		 * @brief Indica si tiene o ha tenido recientemente un objetoo encima
		 * 
		 */
		bool was_object;

	public:
		/**
		 * @brief Constructor de Platform
		 * 
		 * @param scene 
		 * @param pos Posicion inicial
		 * @param rot Rotacion Inicial
		 * @param target Lugar objetivo
		 */
		Platform(Scene *  scene, btVector3 pos, btQuaternion rot, btVector3 target);

		void update(float deltatime) override;
		void reset() override {}

	private:
		/**
		 * @brief Se mueve a la posicion inicial
		 * 
		 * @param deltaTime 
		 */
		void move_to_init(float deltaTime);

		/**
		 * @brief Se mueve a la posicion objetiva
		 * 
		 * @param deltaTime 
		 */
		void move_to_target(float deltaTime);
		/**
		 * @brief Comprueba el sensor/trigger
		 * 
		 */
		void check_sensor();

		/**
		 * @brief Modifica el valor de have to move 
		 * 
		 * @param b 
		 */
		void set_have_to_move(bool b);



	};


}
#endif
