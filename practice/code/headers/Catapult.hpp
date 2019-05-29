

#ifndef CATAPULT_HEADER
#define CATAPULT_HEADER


#include "Entity.hpp"

namespace example
{
	class Catapult : public Entity
	{
	private:
		bool is_firing = false;

		float fire_delay = 2.f;
		float current_time = 0.f;
		bool have_to_fire = false;

		float force = 1000.f;


	public:
		Catapult(Scene * scene, btVector3 pos, btQuaternion rot);

		void update(float deltatime) override;

		void reset() override {}

		void input(float deltaTime) override;

	private:

		void fire();


	
	};
}
#endif
