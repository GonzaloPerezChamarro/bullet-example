/**
 * @file Platform.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class that represents a platform. Kinematic body that moves when the catapult is over it
 * @version 1.0
 * @date 2019-05-30
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef PLATFORM_HEADER
#define PLATFORM_HEADER


#include "Entity.h"


namespace example
{
	class Platform :public Entity
	{
	private:
		/* Target position */
		btVector3 target;

		/* Movement direction */
		btVector3 direction;

		/* Movement speed */
		float speed = .4f;

		/* Delay between player arrives and starts moving */
		float delay = 2.f;

		/* Elapsed time */
		float current_time;

		/* Flag that indicates if the platform is stopped */
		bool stopped;

		/* Flag that indicates if the platform has to move */
		bool have_to_move;

		/* Flag that indicates if the platform had an object on it */
		bool was_object;

	public:
		/**
		 * @brief Constructor
		 * @param scene Pointer to game scene
		 * @param pos Initial position
		 * @param rot Initial rotation
		 * @param target Target location
		 */
		Platform(Scene *  scene, btVector3 pos, btQuaternion rot, btVector3 target);

		void update(float deltatime) override;
		void reset() override {}

	private:
		/**
		 * @brief Moves to initial location
		 * @param deltaTime 
		 */
		void move_to_init(float deltaTime);

		/**
		 * @brief Moves to target location 
		 * @param deltaTime 
		 */
		void move_to_target(float deltaTime);

		/* Checks the sensor */
		void check_sensor();

		/* Set if the platform has to move */
		void set_have_to_move(bool b);
	};
}
#endif
