

#ifndef CUBE_HEADER
#define CUBE_HEADER

#include "Entity.hpp"

namespace example
{
	class Cube : public Entity
	{
	private:

	public:
		Cube(Scene * scene, btVector3 pos, btQuaternion rot, unsigned width, unsigned height, unsigned length);


		void update(float deltaTime) override;

		void reset() override;
	};
}
#endif
