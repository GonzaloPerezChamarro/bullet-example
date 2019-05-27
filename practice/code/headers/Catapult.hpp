

#ifndef CATAPULT_HEADER
#define CATAPULT_HEADER


#include "Entity.hpp"

namespace example
{
	class Catapult : public Entity
	{
	private:
		bool is_firing;


	public:
		Catapult(Scene * scene, btVector3 pos, btQuaternion rot);

		void reset() override {}

		void input(float deltaTime) override;

	private:

		void fire();


	
	};
}
#endif
