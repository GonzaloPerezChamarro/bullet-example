/**
 * @file Key.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Entidad de tipo llave. Permite la apertura de puertas
 * @version 0.1
 * @date 2019-05-30
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef KEY_HEADER
#define KEY_HEADER


#include "Entity.hpp"

#include "Door.hpp"
namespace example
{
	class Key : public Entity
	{
	private:
		/**
		 * @brief Puntero a la puerta que abre
		 * 
		 */
		Door * door;

		/**
		 * @brief Indica si esta recogida
		 * 
		 */
		bool is_taken;

	public:
		/**
		 * @brief Constructor de Key
		 * 
		 * @param scene 
		 * @param pos Posicion inicial
		 * @param rot Rotacion inicial
		 * @param door Puerta
		 */
		Key(Scene * scene, btVector3 pos, btQuaternion rot, Door & door);

		void update(float deltatime) override;

		void reset() override {}
	};
}
#endif
