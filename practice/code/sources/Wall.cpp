

#include "Wall.h"


namespace example
{
	Wall::Wall(Scene * scene, btVector3 pos, btQuaternion rot, Rigidbody::Type type)
		:Entity(scene, pos, rot)
	{
		std::shared_ptr<Rigidbody> wall(new Rigidbody(pos, rot, std::shared_ptr<btBoxShape>(new btBoxShape(btVector3(0.2, 1, 1))),type));

		add_model("wall", wall, "../../assets/wall.obj");
	}
}
