/**
 * @file Catapult.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class that represent a catapult
 * @version 1.0
 * @date 2019-05-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef CATAPULT_HEADER
#define CATAPULT_HEADER


#include "Entity.h"

namespace example
{
	class Catapult : public Entity
	{
	public:
		/**
		 * @brief Constructor
		 * @param scene Pointer to game scene
		 * @param pos Initial oosition
		 * @param rot Initial rotation
		 */
		Catapult(Scene* scene, btVector3 pos, btQuaternion rot);

		void update(float deltatime) override;
		void reset() override {}
		void input(float deltaTime) override;

	private:
		/* Generate a shot action */
		void fire();

	private:
		/* Flag that indicates if the catapult is firing */
		bool is_firing = false;

		/* Time between shots */
		float fire_delay = 2.f;

		/* Elapsed time since last shot */
		float current_time = 0.f;

		/* Flag that indicates if the catapult has to shoot */
		bool have_to_fire = false;

		/* Shot force */
		float force = 1000.f;
	};
}
#endif
