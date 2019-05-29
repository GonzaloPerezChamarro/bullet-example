

#ifndef PLATFORM_HEADER
#define PLATFORM_HEADER


#include "Entity.hpp"


namespace example
{
	class Platform :public Entity
	{
	private:
		btVector3 target;
		btVector3 direction;

		float speed = .4f;

		float delay = 2.f;
		float current_time;

		bool stopped;
		bool have_to_move;

		bool was_object;

	public:
		Platform(Scene *  scene, btVector3 pos, btQuaternion rot, btVector3 target);

		void update(float deltatime) override;
		void reset() override {}

	private:

		void move_to_init(float deltaTime);

		void move_to_target(float deltaTime);

		void check_sensor();

		void set_have_to_move(bool b);



	};


}
#endif
