

#include "Sphere.hpp"


namespace example
{
	Sphere::Sphere(Scene * scene, btVector3 pos, btQuaternion rot)
		:Entity(scene, pos, rot)
	{
		std::shared_ptr<Rigidbody> body(new Rigidbody(pos, rot, std::shared_ptr<btCollisionShape>(new btSphereShape(btScalar(0.5))), Rigidbody::Type::DYNAMIC));

		add_model("sphere", body, "../../assets/sphere.obj", 0.5f);
	}

	void Sphere::update(float deltatime)
	{
		Entity::update(deltatime);
	}

	void Sphere::reset()
	{
	}
}