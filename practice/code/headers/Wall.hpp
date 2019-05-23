
#ifndef WALL_HEADER
#define WALL_HEADER


#include "Entity.hpp"

namespace example
{
	class Wall :public Entity
	{
	private:

	public:

		Wall(Scene * scene, btVector3 pos, btQuaternion rot, Rigidbody::Type type);


		void reset() override {}
	};
}
#endif