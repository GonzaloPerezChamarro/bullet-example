

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

	private:

		void fire();
	
	};
}
#endif
