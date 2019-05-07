#include "Entity.hpp"

namespace example
{
	Entity::Entity(Scene * scene, btVector3 pos)
	{
		transform.setIdentity();
		transform.setOrigin(pos);
		initial_position = pos;
	}
	const btVector3 & Entity::get_current_position() const
	{
		//insert return statement here
	}
}

