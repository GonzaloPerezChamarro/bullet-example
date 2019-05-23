

#ifndef KEY_HEADER
#define KEY_HEADER


#include "Entity.hpp"

#include "Door.hpp"
namespace example
{
	class Key : public Entity
	{
	private:

		Door * door;
		bool is_taken;

	public:
		Key(Scene * scene, btVector3 pos, btQuaternion rot, Door & door);

		void update(float deltatime) override;

		void reset() override {}
	};
}
#endif
