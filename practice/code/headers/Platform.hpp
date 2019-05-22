

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

		float speed = 0.2f;

		bool is_moving;

	public:
		Platform(Scene *  scene, btVector3 pos, btQuaternion rot, btVector3 target);

		void update(float deltatime) override;

	private:

		void move_to_init();

		void move_to_target();

	};
}
#endif
