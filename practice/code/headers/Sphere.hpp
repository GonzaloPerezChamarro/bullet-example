

#ifndef SPHERE_HEADER
#define SPHERE_HEADER


#include "Entity.hpp"


namespace example
{
	class Sphere : public Entity
	{

	public:
		Sphere(Scene * scene, btVector3 pos, btQuaternion rot);

		void update(float deltatime) override;

		void reset() override;

	};
}
#endif
