

#include "Key.hpp"

namespace example
{
	Key::Key(Scene * scene, btVector3 pos, btQuaternion rot, Door & door)
		:Entity(scene, pos, rot), door(&door), is_taken(false)
	{
		std::shared_ptr<Rigidbody> key(new Rigidbody(pos, rot, std::shared_ptr<btCollisionShape>(new btSphereShape(btScalar(0.3f))), Rigidbody::Type::STATIC));
		add_model("key", key, "../../assets/key.obj", 1.f);

		std::shared_ptr<Sensor> sensor(new Sensor(pos, rot, std::shared_ptr<btCollisionShape>(new btSphereShape(btScalar(0.3f)))));
		add_sensor("sensor", sensor);
	}

	void Key::update(float deltatime)
	{
		Entity::update(deltatime);

		if (is_taken) return;

		size_t overlapping_objects = sensors["sensor"]->get_sensor()->getNumOverlappingObjects();

		if (overlapping_objects > 0)
		{
			is_taken = true;

			door->get_mesh("door")->set_visible(false);
			door->get_rigidbody("door")->get_rigidbody()->setCollisionFlags(btCollisionObject::CF_NO_CONTACT_RESPONSE);
			
		}
	}
}