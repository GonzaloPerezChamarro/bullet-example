

#include "Sphere.hpp"


namespace example
{
	Sphere::Sphere(Scene * scene, btVector3 pos, btQuaternion rot, Rigidbody::Type type )
		:Entity(scene, pos, rot)
	{
		std::shared_ptr<Rigidbody> body(new Rigidbody(pos, rot, std::shared_ptr<btCollisionShape>(new btSphereShape(btScalar(0.3))), type));

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