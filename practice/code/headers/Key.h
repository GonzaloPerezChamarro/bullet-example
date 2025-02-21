/**
 * @file Key.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class that represents a key that open doors
 * @version 1.0
 * @date 2019-05-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef KEY_HEADER
#define KEY_HEADER


#include "Entity.h"

#include "Door.h"
namespace example
{
	class Key : public Entity
	{
	private:
		/* Pointer to the door which the key can open */
		Door * door;

		/* Flag that indicates if the key has been taken */
		bool is_taken;

	public:
		/**
		 * @brief Constructor
		 * @param scene Pointer to game scene
		 * @param pos Initial position
		 * @param rot Initial rotation
		 * @param door Pointer to door to open
		 */
		Key(Scene * scene, btVector3 pos, btQuaternion rot, Door & door);

		void update(float deltatime) override;
		void reset() override {}
	};
}
#endif
