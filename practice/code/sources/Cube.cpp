

#include "Cube.hpp"
#include "..\headers\Cube.hpp"

#include <map>
#include <string>

namespace example
{
	Cube::Cube(Scene * scene, btVector3 pos, btQuaternion rot, unsigned width, unsigned height, unsigned length)
		:Entity(scene, pos, rot)
	{

		std::shared_ptr<Rigidbody> cube(new Rigidbody(pos, rot, std::shared_ptr<btBoxShape>(new btBoxShape(btVector3(width, height, length))), Rigidbody::Type::STATIC));
		
		cube->get_rigidbody()->setLinearFactor(btVector3(0.f, 0.f, 1.f));
		cube->get_rigidbody()->setAngularFactor(btVector3(0.f, 0.f, 0.f));

		
		bodies["body"] = cube;
	}

	void Cube::update(float deltaTime)
	{
	}

	void Cube::render(sf::RenderWindow & renderer)
	{
	}
}