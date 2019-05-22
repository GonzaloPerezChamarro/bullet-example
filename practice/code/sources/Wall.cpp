

#include "Wall.hpp"


namespace example
{
	Wall::Wall(Scene * scene, btVector3 pos, btQuaternion rot)
		:Entity(scene, pos, rot)
	{
		std::shared_ptr<Rigidbody> wall(new Rigidbody(pos, rot, std::shared_ptr<btBoxShape>(new btBoxShape(btVector3(1, 1, 1))),Rigidbody::Type::STATIC));

		add_model("wall", wall, "../../assets/wall.obj");
	}

}
