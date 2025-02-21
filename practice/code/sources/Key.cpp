

#include "Key.h"

namespace example
{
	Key::Key(Scene * scene, btVector3 pos, btQuaternion rot, Door & door)
		:Entity(scene, pos, rot), door(&door), is_taken(false)
	{
		// Create the key
		std::shared_ptr<Rigidbody> key(new Rigidbody(pos, rot, std::shared_ptr<btCollisionShape>(new btSphereShape(btScalar(0.3f))), Rigidbody::Type::STATIC));
		add_model("key", key, "../../assets/key.obj", 1);

		// Create the trigger that checks when the key is taken
		std::shared_ptr<Sensor> sensor(new Sensor(pos, rot, std::shared_ptr<btBoxShape>(new btBoxShape(btVector3(0.3, 0.3, 0.3)))));
		add_sensor("sensor", sensor);
	}

	void Key::update(float deltatime)
	{
		Entity::update(deltatime);

		if (is_taken) return;

		// Checks the sensor state
		size_t overlapping_objects = sensors["sensor"]->get_sensor()->getNumOverlappingObjects();

		if (overlapping_objects > 0)
		{
			is_taken = true;

			// When the key is taken, open the door
			get_mesh("key")->set_visible(false);
			get_rigidbody("key")->get_rigidbody()->setCollisionFlags(btCollisionObject::CF_NO_CONTACT_RESPONSE);

			door->get_rigidbody("door")->get_rigidbody()->setCollisionFlags(btCollisionObject::CF_NO_CONTACT_RESPONSE);
			door->get_mesh("door")->set_visible(false);
		}
	}
}