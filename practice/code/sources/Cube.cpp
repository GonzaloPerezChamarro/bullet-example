

#include "Cube.hpp"
#include "..\headers\Cube.hpp"

#include <map>
#include <string>

namespace example
{ 
	Cube::Cube(Scene * scene, btVector3 pos, btQuaternion rot, Rigidbody::Type type)
		:Entity(scene, pos, rot)
	{

		std::shared_ptr<Rigidbody> body(new Rigidbody(pos, rot, std::shared_ptr<btBoxShape>(new btBoxShape(btVector3(1, 1, 1))), type));
		
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