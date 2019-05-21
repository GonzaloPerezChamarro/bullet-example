

#include "Cube.hpp"
#include "..\headers\Cube.hpp"

#include <map>
#include <string>

namespace example
{
	Cube::Cube(Scene * scene, btVector3 pos, btQuaternion rot)
		:Entity(scene, pos, rot)
	{

		std::shared_ptr<Rigidbody> body(new Rigidbody(pos, rot, std::shared_ptr<btBoxShape>(new btBoxShape(btVector3(0.5, 0.5, 0.5))), Rigidbody::Type::STATIC));
		
		add_model("box", body, "../../assets/cube.obj");

		
	}

	void Cube::update(float deltaTime)
	{
		Entity::update(deltaTime);
	}
	void Cube::reset()
	{
	}
}